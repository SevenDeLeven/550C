#include "converter.h"
#include <string>

char* convertIntToString(int i) {
  return const_cast<char*>(std::to_string(i).c_str());
}
char* convertLongToString(long l) {
  return const_cast<char*>(std::to_string(l).c_str());
}
char* convertDoubleToString(double d) {
  return const_cast<char*>(std::to_string(d).c_str());
}
char* convertFloatToString(float f) {
  return const_cast<char*>(std::to_string(f).c_str());
}
char* convertShortToString(short s) {
  return const_cast<char*>(std::to_string(s).c_str());
}
char* convertBoolToString(bool b) {
  return const_cast<char*>(std::to_string(b).c_str());
}
