#ifndef TIMERS_H
#define TIMERS_H

class Timer {
private:
  unsigned long initialTime;
public:
  Timer();
  virtual ~Timer();
  void resetTimer();
  unsigned long getTimeMillis();
};

#endif
