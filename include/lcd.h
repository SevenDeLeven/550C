#ifndef LCD_H
#define LCD_H

#include "API.h"

class LCD {
private:
  PROS_FILE * lcd;
  char* ln1;
  char* ln2;
public:
  LCD (PROS_FILE * lcd);
  virtual ~LCD ();
  void updateButtons();
  void updateLCD();
  void clearLCD();
  void println(const char* strng);
  void setLine(unsigned char line, const char* strng);
  void clearLine(unsigned char line);
  bool getLeftButtonPressed();
  bool getRightButtonPressed();
  bool getCenterButtonPressed();
};

#endif
