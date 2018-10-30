#include "API.h"
#include "timers.h"

Timer::Timer() {
  this->initialTime = millis();
}

Timer::~Timer() {

}

void Timer::resetTimer() {
  this->initialTime = millis();
}

unsigned long Timer::getTimeMillis() {
  return millis()-this->initialTime;
}
