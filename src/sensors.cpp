#include "API.h"
#include "sensors.h"

AnalogSensor::AnalogSensor(unsigned char port) {
  this->m_port = port;
}

AnalogSensor::~AnalogSensor() {

}

void AnalogSensor::calibrate() {
  analogCalibrate(this->m_port);
}

int AnalogSensor::getCalibratedValue() {
  return analogReadCalibrated(this->m_port);
}

int AnalogSensor::getHRCalibratedValue() {
  return analogReadCalibratedHR(this->m_port);
}

unsigned char AnalogSensor::getPort() {
  return this->m_port;
}

int AnalogSensor::getValue() {
  return analogRead(this->m_port);
}





IMESensor::IMESensor(unsigned char address) {
  this->m_imeAddress = address;
}

void IMESensor::reset() {
  imeReset(this->m_imeAddress);
}

unsigned char IMESensor::getAddress() {
  return this->m_imeAddress;
}

int IMESensor::getDistance() {
  int dist = 0;
  if (!imeGet(this->m_imeAddress, &dist)) {
    return 0;
  }
  return dist;
}
