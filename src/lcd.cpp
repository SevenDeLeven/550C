#include "lcd.h"
#include "API.h"

LCD::LCD(PROS_FILE * lcd) {
  this->lcd = lcd;
}

LCD::~LCD() {

}

void LCD::updateLCD() {
  lcdSetText(this->lcd, 1, ln1.c_str());
  lcdSetText(this->lcd, 2, ln2.c_str());
}

void LCD::clearLCD() {
  ln1 = "";
  ln2 = "";
  this->updateLCD();
}

void LCD::println(std::string strng)  {
  this->ln1 = this->ln2;
  this->ln2 = strng;
  this->updateLCD();
}

void LCD::setLine(unsigned char line, std::string strng) {
  if (line == 1) {
    ln1 = strng;
  } else if (line == 2) {
    ln2 = strng;
  }
  this->updateLCD();
}
