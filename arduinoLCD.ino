/**
   Arduino Calculator

   Copyright (C) 2020, Uri Shaked.
   Released under the MIT License.
*/

#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

/* Display */
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

char* stringsToDisplay[] = 
{ 
 //********************************  <- this is the max length
  "Hello world", 
  "This is a sample string", 
  "And another one", 
  "These will be displayed on LCD",
  "They have to be shorter than 32"
};
const int numStrings = sizeof(stringsToDisplay) / sizeof(stringsToDisplay[0]);

void show() {
  int idx = 0;
  int line = 0;
  while(true) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    String message = stringsToDisplay[idx];

    for (byte i = 0; i < message.length(); i++) {
      lcd.print(message[i]);
      if(i > 0 && i%15==0) 
      {
        lcd.setCursor(0, 1);
      }
      delay(100);
    }

    idx++;
    if(idx>numStrings-1) idx=0;

    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {  
  show();
}
