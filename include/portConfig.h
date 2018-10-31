#ifndef PORTCONFIG_H
#define PORTCONFIG_H

#include "motors.h"
#include "sensors.h"
#include "lcd.h"

extern AnalogSensor leftLiftPotent;
extern AnalogSensor rightLiftPotent;

extern Motor leftDrive1;
extern Motor leftDrive2;
extern Motor leftLift;
extern Motor turnTable;
extern Motor flyWheel;
extern Motor rightLift;
extern Motor rightDrive1;
extern Motor rightDrive2;
extern Motor intake;

extern MotorGroup leftDrive;
extern MotorGroup rightDrive;

extern LCD lcd;

extern IMESensor leftIME;
extern IMESensor rightIME;

extern int auton;

#endif
