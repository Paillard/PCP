#include <LiquidCrystal.h>

// using LCM1602C

#define RS_PIN 7
#define EN_PIN 8
#define DB4_PIN 9
#define DB5_PIN 10
#define DB6_PIN 11
#define DB7_PIN 12

// initialize the library
LiquidCrystal lcd(RS_PIN, EN_PIN, DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
