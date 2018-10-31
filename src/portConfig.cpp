#include "portConfig.h"

AnalogSensor leftLiftPotent(1);
AnalogSensor rightLiftPotent(2);
Motor leftDrive1(2);
Motor leftDrive2(3);
Motor leftLift(4);
Motor turnTable(5);
Motor flyWheel(6);
Motor rightLift(7);
Motor rightDrive1(8);
Motor rightDrive2(9);
Motor intake(10);
Motor leftDriveMotors[2] = *(new Motor[2]{leftDrive1, leftDrive2});
Motor rightDriveMotors[2] = *(new Motor[2]{rightDrive1, rightDrive2});

MotorGroup leftDrive(leftDriveMotors, 2);
MotorGroup rightDrive(rightDriveMotors, 2);

int auton = 0;
