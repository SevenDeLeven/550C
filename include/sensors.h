#ifndef SENSORS_H
#define SENSORS_H

class AnalogSensor {
private:
  unsigned char m_port;
public:
  AnalogSensor(unsigned char port);
  virtual ~AnalogSensor();
  unsigned char getPort();
  int getValue();
  void calibrate();
  int getCalibratedValue();
  int getHRCalibratedValue();
};

class IMESensor {
private:
  unsigned char m_imeAddress;
public:
  IMESensor(unsigned char imeAddress);
  virtual ~IMESensor();
  void reset();
  unsigned char getAddress();
  int getDistance();
};

#endif
