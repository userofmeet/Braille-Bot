#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

//  S1, S2
//  S3, S4
//  S5, S6
//  Placement of the servo motors 

int pos1 = 0; // Initial position of servo1
int pos2 = 0; 
int pos3 = 0; 
int pos4 = 0; 
int pos5 = 0; 
int pos6 = 0; 

int n=30; //Degrees of the servo motor
int d=100; //Delay of the servo motor

void setup() 
{
  Serial.begin(9600);
  servo1.attach(6);
  servo2.attach(7);
  servo3.attach(8);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);  
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo5.write(pos5);
  servo6.write(pos6);
  lcd.print("Enter character:");
  Serial.println("Enter  character: ");
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    char input = Serial.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    
    if (input == 'A' || input == 'a') 
    {
      // Rotate servo1 by n degrees
      pos1 += n;
      if (pos1 > 180) pos1 = 180; // Limit to 180 degrees
      servo1.write(pos1);
      lcd.setCursor(0,0);
      lcd.print("Entered");
      lcd.setCursor(0,1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered character: ");
      Serial.println(input);
      delay(d);
      pos1 = 0;
      servo1.write(pos1);
    } 

    else if (input == 'B' || input == 'b') 
    {
      pos1 += n;
      pos3 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos3 > 180) pos3 = 180;
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      servo1.write(pos1);
      servo3.write(pos3);
      } 

    else if (input == 'C' || input == 'c') 
    {
      pos1 += n;
      pos2 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      }

    else if (input == 'D' || input == 'd') 
    {
      pos1 += n;
      pos2 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180; 
      if (pos4 > 180) pos4 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo4.write(pos4);
      }

    else if (input == 'E' || input == 'e') 
    {
      pos1 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos4 > 180) pos4 = 180; 
      servo1.write(pos1);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo4.write(pos4);
    }
      
    else if (input == 'F' || input == 'f') 
    {
      pos1 += n;
      pos2 += n;
      pos3 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180; 
      if (pos3 > 180) pos3 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
    }

    else if (input == 'G' || input == 'g') 
    {
      pos1 += n;
      pos2 += n;
      pos3 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
      }

    else if (input == 'H' || input == 'h') 
    {
      pos1 += n;
      pos3 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180; 
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo3.write(pos3);
      servo4.write(pos4);
    }

    else if (input == 'I' || input == 'i') 
    {
      pos2 += n;
      pos3 += n;
      if (pos2 > 180) pos2 = 180; 
      if (pos3 > 180) pos3 = 180;
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      servo1.write(pos2);
      servo3.write(pos3);
    }

    else if (input == 'J' || input == 'j') 
    {
      pos2 += n;
      pos3 += n;
      pos4 += n;
      if (pos2 > 180) pos2 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180; 
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
    }

    else if (input == 'K' || input == 'k') 
    {
      pos1 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo5.write(pos5);
    }

    else if (input == 'L' || input == 'l') 
    {
      pos1 += n;
      pos3 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo3.write(pos3);
      servo5.write(pos5);
    }

    else if (input == 'M' || input == 'm') 
    {
      pos1 += n;
      pos2 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
    }

    else if (input == 'N' || input == 'n') 
    {
      pos1 += n;
      pos2 += n;
      pos4 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180; 
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos4 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo4.write(pos4);
      servo5.write(pos5);
    }
      
    else if (input == 'O' || input == 'o') 
    {
      pos1 += n;
      pos4 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos4 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo4.write(pos4);
      servo5.write(pos5);
    }

    else if (input == 'P' || input == 'p') 
    {
      pos1 += n;
      pos2 += n;
      pos3 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
      servo5.write(pos5);
    }

    else if (input == 'Q' || input == 'q') 
    {
      pos1 += n;
      pos2 += n;
      pos3 += n;
      pos4 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos2 > 180) pos2 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
      servo5.write(pos5);
    }

    else if (input == 'R' || input == 'r') 
    {
      pos1 += n;
      pos3 += n;
      pos4 += n;
      pos5 += n;
      if (pos1 > 180) pos1 = 180; 
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      pos4 = 0;
      pos5 = 0;
      servo1.write(pos1);
      servo3.write(pos3);
      servo4.write(pos4);
      servo5.write(pos5);
    }

    else if (input == 'S' || input == 's') 
    {
      pos2 += n;
      pos3 += n;
      pos5 += n;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      pos5 = 0;
      servo2.write(pos2);
      servo3.write(pos3);
      servo5.write(pos5);
    }

    else if (input == 'T' || input == 't') 
    {
      pos2 += n;
      pos3 += n;
      pos4 += n;
      pos5 += n;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180; 
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      pos5 = 0;
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
      servo5.write(pos5);  
    }

    else if (input == 'U' || input == 'u') 
    {
      pos1 += n;
      pos5 += n;
      pos6 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos5 > 180) pos5 = 180;
      if (pos6 > 180) pos6 = 180; 
      servo1.write(pos1);
      delay(d);
      servo5.write(pos5);
      delay(d);
      servo6.write(pos6);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos5 = 0;
      pos6 = 0;
      servo1.write(pos1);
      servo5.write(pos5);
      servo6.write(pos6);
    }

    else if (input == 'V' || input == 'v') 
    {
      pos1 += n;
      pos3 += n;
      pos5 += n;
      pos6 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos5 > 180) pos5 = 180;
      if (pos6 > 180) pos6 = 180; 
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo5.write(pos5);
      delay(d);
      servo6.write(pos6);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      pos5 = 0;
      pos6 = 0;
      servo1.write(pos1);
      servo3.write(pos3);
      servo5.write(pos5);
      servo6.write(pos6);  
    }

    else if (input == 'W' || input == 'w') 
    {
      pos2 += n;
      pos3 += n;
      pos4 += n;
      pos6 += n;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      if (pos6 > 180) pos6 = 180; 
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo6.write(pos6);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      pos6 = 0;
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
      servo6.write(pos6);
    }

    else if (input == 'X' || input == 'x') 
    {
      pos1 += n;
      pos2 += n;
      pos5 += n;
      pos6 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      if (pos5 > 180) pos5 = 180;
      if (pos6 > 180) pos6 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo5.write(pos5);
      delay(d);
      servo6.write(pos6);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos5 = 0;
      pos6 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo5.write(pos5);
      servo6.write(pos6);
    }

    else if (input == 'Y' || input == 'y') 
    {
      pos1 += n;
      pos2 += n;
      pos4 += n;
      pos5 += n;
      pos6 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180;
      if (pos6 > 180) pos6 = 180; 
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      servo6.write(pos6);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos4 = 0;
      pos5 = 0;
      pos6 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo4.write(pos4);
      servo5.write(pos5);
      servo6.write(pos6);
    }

    else if (input == 'Z' || input == 'z') 
    {
      pos1 += n;
      pos4 += n;
      pos5 += n;
      pos6 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos4 > 180) pos4 = 180;
      if (pos5 > 180) pos5 = 180;
      if (pos6 > 180) pos6 = 180; 
      servo1.write(pos1);
      delay(d);
      servo4.write(pos4);
      delay(d);
      servo5.write(pos5);
      delay(d);
      servo6.write(pos6);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos4 = 0;
      pos5 = 0;
      pos6 = 0;
      servo1.write(pos1);
      servo4.write(pos4);
      servo5.write(pos5);
      servo6.write(pos6);
    }
    
    else if (input == 1)
    {
      pos1 += n;
      if (pos1 > 180) pos1 = 180;
      servo1.write(pos1);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      servo1.write(pos1);
    }

    else if (input == 2)
    {
      pos1 += n;
      pos3 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos3 > 180) pos3 = 180;
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      servo1.write(pos1);
      servo3.write(pos3);  
    }

    else if (input == 3)
    {
      pos1 += n;
      pos2 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
    }

    else if (input == 4)
    {
      pos1 += n;
      pos2 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      if (pos4 > 180) pos4 = 180;
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo4.write(pos4);
    }

    else if (input == 5)
    {
      pos1 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos4 > 180) pos4 = 180;
      servo1.write(pos1);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo4.write(pos4);
    }

    else if (input == 6)
    {
      pos1 += n;
      pos2 += n;
      pos3 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
    }

    else if (input == 7)
    {
      pos1 += n;
      pos2 += n;
      pos3 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      servo1.write(pos1);
      delay(d);
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
    }

    else if (input == 8)
    {
      pos1 += n;
      pos3 += n;
      pos4 += n;
      if (pos1 > 180) pos1 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      servo1.write(pos1);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos1 = 0;
      pos3 = 0;
      pos4 = 0;
      servo1.write(pos1);
      servo3.write(pos3);
      servo4.write(pos4);
    } 

    else if (input == 9)
    {
      pos2 += n;
      pos3 += n;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      servo2.write(pos2);
      servo3.write(pos3);
    } 

    else if (input == 0)
    {
      pos2 += n;
      pos3 += n;
      pos4 += n;
      if (pos2 > 180) pos2 = 180;
      if (pos3 > 180) pos3 = 180;
      if (pos4 > 180) pos4 = 180;
      servo2.write(pos2);
      delay(d);
      servo3.write(pos3);
      delay(d);
      servo4.write(pos4);
      delay(d);
      lcd.setCursor(0, 0);
      lcd.print("Entered ");
      lcd.setCursor(0, 1);
      lcd.print("Character: ");
      lcd.print(input);
      Serial.println("Entered Character: ");
      Serial.println(input);
      pos2 = 0;
      pos3 = 0;
      pos4 = 0;
      servo2.write(pos2);
      servo3.write(pos3);
      servo4.write(pos4);
    }

    else
    {
      Serial.println("Invalid input");
      lcd.print("Invalid input");
    } 
  }
}
