/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
  leftLiftPotent = AnalogSensor(1);
  rightLiftPotent = AnalogSensor(2);
  leftDrive1 = Motor(2);
  leftDrive2 = Motor(3);
  leftLift = Motor(4);
  turnTable = Motor(5);
  flyWheel = Motor(6);
  rightLift = Motor(7);
  rightDrive1 = Motor(8);
  rightDrive2 = Motor(9);
  intake = Motor(10);
  Motor leftDriveMotors[2] = *(new Motor[2]{leftDrive1, leftDrive2});
  Motor rightDriveMotors[2] = *(new Motor[2]{rightDrive1, rightDrive2});

  leftDrive = MotorGroup(leftDriveMotors, 2);
  rightDrive = MotorGroup(rightDriveMotors, 2);
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
#include <vector>
#include "motors.h"
void initialize() {
  if (imeInitializeAll() != 2) {

  }

	clearLCDLine(0);
	clearLCDLine(1);
	bool rightPressedPrev = false;
	bool leftPressedPrev = false;
	bool centerPressedPrev = false;
	bool changedLCD = true;

	while (bIfiRobotDisabled || debug) {
		bool rightPressed = rightLCDButtonPressed();
		bool leftPressed = leftLCDButtonPressed();
		bool centerPressed = centerLCDButtonPressed();
		if (rightPressed && !rightPressedPrev) {
			auton++;
			auton%=s_autonomousNames;
			changedLCD = true;
		}
		if (leftPressed && !leftPressedPrev) {
			auton--;
			auton = auton < 0 ? s_autonomousNames-1 : auton;
			changedLCD = true;
		}
		if (centerPressed && !centerPressedPrev) {
			//CENTER BUTTON PRESSED
			debug = false;
		}
		if (changedLCD) {
			clearLCDLine(0);
			displayLCDCenteredString(0,getAutonName());
			clearLCDLine(1);
			displayLCDCenteredString(1,autonomousNames[auton]);
		}
		rightPressedPrev = rightPressed;
		leftPressedPrev = leftPressed;
		centerPressedPrev = centerPressed;
		changedLCD = false;
	}
}
