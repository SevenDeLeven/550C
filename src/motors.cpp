#include "API.h"
#include "motors.h"

Motor::Motor(unsigned char port) {
  this->m_port = port;
  this->m_reversed = false;
}

Motor::~Motor() {

}

void Motor::setReversed(bool reversed) {
  this->m_reversed = reversed;
}

void Motor::setSpeed(int speed) {
  motorSet(this->m_port, speed * (this->m_reversed ? -1 : 1));
}

void Motor::reverse() {
  this->m_reversed = !this->m_reversed;
}

void Motor::stop() {
  motorStop(this->m_port);
}

bool Motor::getReversed() {
  return this->m_reversed;
}



MotorGroup::MotorGroup(Motor motors[], int motorCount) {
  this->m_motorCount = motorCount;
  this->m_motors = motors;
  this->m_reversed = false;
}

MotorGroup::~MotorGroup() {

}

void MotorGroup::setReversed(bool reversed) {
  this->m_reversed = reversed;
}

void MotorGroup::setSpeed(int speed) {
  for (int i = 0; i < this->m_motorCount; i++) {
    this->m_motors[i].setSpeed(speed * (this->m_reversed ? -1 : 1));
  }
}

void MotorGroup::reverse() {
  this->m_reversed = !this->m_reversed;
}

bool MotorGroup::getReversed() {
  return this->m_reversed;
}
