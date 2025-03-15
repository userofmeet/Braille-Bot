#include <LiquidCrystal_I2C.h>
#include <mechButton.h>
#include <Servo.h>
#include <serialStr.h>
#include <resizeBuff.h>
#include <autoPOT.h>
#include <mapper.h>
#include <SoftwareSerial.h>  // Include SoftwareSerial for Bluetooth
#include "Braille_Symbols.h"

#define MIN_MS 750
#define MAX_MS 2000

const int servoPins[] = {10, 5, 9, 6, 8, 7};
int asciiValue;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo[6];
mechButton repeatBtn(2);
mechButton backBtn(3);
mechButton fwdBtn(4);
serialStr serialMgr;
char* aStr;
int strIndex;
timeObj stringTimer(1000,false);
autoPOT potMgr(A0);
mapper potMapper(0,1023,MAX_MS,MIN_MS);
float msPerChar;
bool newDelay;

// Bluetooth module HC-05 connected to pins 11 (RX) and 12 (TX)
SoftwareSerial BTSerial(11, 12);

void backBtnClk(void) 
{
  if (!backBtn.getState()) 
  {
    if (asciiValue > 32) 
    {
      asciiValue--;
    }
    showChar(asciiValue);
  }
}

void fwdBtnClk(void) 
{
  if (!fwdBtn.getState()) 
  {
    if (asciiValue < 90) 
    {
      asciiValue++;
    }
    showChar(asciiValue);
  }
}

void receivedStr(char* inStr) 
{
  int numBytes;
  Serial.println(inStr);
  BTSerial.println(inStr);  // Also send received text to Bluetooth app

  if (aStr) 
  {
    Serial.println("Sorry, already reading a string");
    return;
  } 
  else 
  {
    numBytes = strlen(inStr);
    numBytes++;
    if (resizeBuff(numBytes, &aStr)) 
    {
      strcpy(aStr, inStr);
      strIndex = 0;
      showChar((int)(aStr[strIndex]));
      stringTimer.start();
    }
  }
}

void newValue(int inVal)
{
  msPerChar = potMapper.map(inVal);
  newDelay = true;
}

void moveServos(int value)  
{
  byte moveByte = symbols[value - 32];
  if (moveByte & 128)  
  {
    for (int idx = 0; idx <= 5; idx++)  
    {
      servo[idx].write(90);
    }
  } 
  else  
  {
    moveByte & 0b00100000 ? servo[0].write(0) : servo[0].write(90);
    moveByte & 0b00010000 ? servo[1].write(180) : servo[1].write(90);
    moveByte & 0b00001000 ? servo[2].write(0) : servo[2].write(90);
    moveByte & 0b00000100 ? servo[3].write(180) : servo[3].write(90);
    moveByte & 0b00000010 ? servo[4].write(0) : servo[4].write(90);
    moveByte & 0b00000001 ? servo[5].write(180) : servo[5].write(90);
  }
}

void showChar(int charCode) 
{
  char myChar = (char)charCode;
  byte moveByte = symbols[charCode - 32];
  lcd.setCursor(12, 0);
  lcd.print(myChar);
  lcd.setCursor(10, 1);
  if (moveByte & 128)  
  {
  
  } 
  else 
  {
    for (int bit = 5; bit >= 0; bit--)  
    {
      lcd.print(bitRead(moveByte, bit));
    }
  }
  moveServos(charCode);
}

void setup() 
{
  Serial.begin(9600);
  BTSerial.begin(9600);  // Initialize Bluetooth module
  lcd.init();
  lcd.backlight();
  
  for (int idx = 0; idx <= 5; idx++)  
  {
    servo[idx].attach(servoPins[idx]);
  }
  
  fwdBtn.setCallback(fwdBtnClk);
  backBtn.setCallback(backBtnClk);
  repeatBtn.setCallback(showChar);
  serialMgr.setCallback(receivedStr);
  potMgr.setCallback(newValue);
  aStr = NULL;
  newDelay = false;

  // splash screen
  lcd.setCursor(4, 0);
  lcd.print("Braille");
  lcd.setCursor(1, 1);
  lcd.print("Trainer v1.3.0");
  delay(1000);
  lcd.clear();

  // initialize
  lcd.setCursor(0, 0);
  lcd.print("Character :");
  lcd.setCursor(0, 1);
  lcd.print("Braille :");
  asciiValue = 65;  // A
  showChar(asciiValue);

  Serial.println("*** Type a string to be read. ***");
  Serial.println("Use the knob to adjust reading speed.");
}

void loop() 
{
  idle();  // Let background tasks, like the buttons, run.

  // Check if Bluetooth has data
  if (BTSerial.available()) 
  {
    String btInput = BTSerial.readString();
    Serial.println("Bluetooth Input: " + btInput);
    receivedStr((char*)btInput.c_str());
  }

  // Check if Serial Monitor has data
  if (Serial.available()) 
  {
    String serialInput = Serial.readString();
    Serial.println("Serial Input: " + serialInput);
    receivedStr((char*)serialInput.c_str());
  }

  if (aStr) 
  {  
    if (stringTimer.ding()) 
    {  
      strIndex++;  
      if (aStr[strIndex] == '\0') 
      {  
        resizeBuff(0, &aStr);  
        stringTimer.reset();  
      } 
      else 
      {  
        showChar((int)(aStr[strIndex]));  
        if (newDelay) 
        {  
          stringTimer.setTime(msPerChar);  
          newDelay = false;  
        } 
        else 
        {  
          stringTimer.stepTime();  
        }
      }
    }
  }
}
