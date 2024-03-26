// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }

#include <Arduino.h>
#include <LiquidCrystal.h>

void printPadded(int);

String workText = "work: ";
String restText = "rest: ";
int cursor_line = 0;
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(workText);
  lcd.setCursor(0, 1);
  lcd.print(restText);
  lcd.setCursor(0, 0);
}

void loop() {
  unsigned long current = millis();
  int s = (current / 1000) % 60; // Определение секунд
  int m = (current / 60000) % 60; // Определение минут
  int h = (current / 3600000) % 24; // Определение часов

  if (s == 45 && cursor_line == 0){
    cursor_line = 1;
  } else if (s == 15 && cursor_line == 1) {
    cursor_line = 0;
  }

  lcd.setCursor(6, cursor_line);
  
  printPadded(m);
  lcd.print(":");
  printPadded(s);

  delay(1000);
  //clearNumbers(); 
}

void printPadded(int value) {
  if (value < 10) {
    lcd.print("0");
  }
  lcd.print(value);
}