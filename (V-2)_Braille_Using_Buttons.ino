#include <LiquidCrystal_I2C.h>
#include <mechButton.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2);  
mechButton fwdBtn(2);
mechButton repeatBtn(3);
mechButton backBtn(4);
int theValue;
Servo theServo;

void setup() 
{
  lcd.init();                      
  lcd.backlight();               
  lcd.setCursor(0,0);
  lcd.print("Current :");
  theValue = (int)'a';
  showChar();
  fwdBtn.setCallback(fwdBtnClk);
  backBtn.setCallback(backBtnClk);
  repeatBtn.setCallback(showChar);
  theServo.attach(12);
}

void showChar(void) {
  char  myChar;
  myChar = (char)theValue;
  lcd.setCursor(10,1);              
  lcd.print(myChar);
  theServo.write(180);
  delay(500);
  theServo.write(0);
}

void fwdBtnClk(void) 
{
  if (!fwdBtn.getState()) {
    if (theValue<(int)('z')) {
      theValue++;
    }
    showChar();
  }
}

void backBtnClk(void) {
  if (!backBtn.getState()) {
    if (theValue>(int)('a')) {
      theValue--;
    }
    showChar();
  }
}

void loop() {  
  idle();   // Let background tasks, like the buttons, do their thing.
}
