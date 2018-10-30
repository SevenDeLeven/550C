#ifndef LCD_H
#define LCD_H

#include <string>

class PROS_FILE;

class LCD {
private:
  PROS_FILE * lcd;
  std::string ln1, ln2;
public:
  LCD (PROS_FILE * lcd);
  virtual ~LCD ();
  void updateLCD();
  void clearLCD();
  void println(std::string strng);
  void setLine(unsigned char line, std::string strng);
  void clearLine(unsigned char line);
};

#endif
