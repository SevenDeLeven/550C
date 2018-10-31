#include "lcd.h"
#include "API.h"

LCD::LCD(PROS_FILE * lcd) {
  this->lcd = lcd;
  lcdInit(lcd);
}

LCD::~LCD() {

}

void LCD::updateLCD() {
  lcdSetText(this->lcd, 1, ln1);
  lcdSetText(this->lcd, 2, ln2);
}

void LCD::clearLCD() {
  ln1 = const_cast<char*>("");
  ln2 = const_cast<char*>("");
  this->updateLCD();
}

void LCD::clearLine(unsigned char line) {
  
}

void LCD::println(const char* strng)  {
  this->ln1 = this->ln2;
  this->ln2 = const_cast<char*>(strng);
  this->updateLCD();
}

void LCD::setLine(unsigned char line, const char* strng) {
  if (line == 1) {
    ln1 = const_cast<char*>(strng);
  } else if (line == 2) {
    ln2 = const_cast<char*>(strng);
  }
  this->updateLCD();
}
