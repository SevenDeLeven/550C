#ifndef MOTORS_H
#define MOTORS_H

class Motor {
private:
  unsigned char m_port;
  bool m_reversed;
public:
  Motor(unsigned char port);
  virtual ~Motor();
  void setReversed(bool reversed);
  void reverse();
  void setSpeed(int speed);
  void stop();
  bool getReversed();
};

class MotorGroup {
private:
  Motor* m_motors;
  int m_motorCount;
  bool m_reversed;
public:
  MotorGroup(Motor motors[], int motorCount);
  virtual ~MotorGroup();
  void setReversed(bool reversed);
  void reverse();
  void setSpeed(int speed);
  void stop();
  bool getReversed();
};

#endif
