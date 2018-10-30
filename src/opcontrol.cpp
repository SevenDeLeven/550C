/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "joystick.h"

int turnTblSpeed = 0;

int turnTblButtonPrev = 0;
int turnTblButton = 0;

bool flyWheelToggle = false;
int flyWheelSpeed = 127;

bool flyWheelToggleB = false;

int direction = 1;

void operatorControl() {
	JoystickButtonGroup intakeButton(1, 5);
	JoystickButtonGroup turnTableButton(1, 6);
	JoystickToggleButton directionButton(1, 7, JOY_DOWN);
	JoystickToggleButton flyWheelButton(1, 8, JOY_DOWN);

	JoystickAnalog forwardAxis(1, 3);
	JoystickAnalog turnAxis(1, 4);
	JoystickAnalog liftAxis(1, 2);
	JoystickAnalog liftTiltAxis(1, 1);

	while (true) {
		bool nChangeButton = joystickGetDigital(1, 7, JOY_DOWN) == 1;
		bool nFlyWheelToggleB = joystickGetDigital(1, 8, JOY_DOWN) == 1;
		float forw 		= forwardAxis.getValue() * direction;
		float turn		= turnAxis.getValue();
		float left 		= forw + turn;
		float right 	= forw - turn;
		int up = liftAxis.getValue();
		int tilt = liftTiltAxis.getValue();
		float upLeft	= up+(tilt*tiltSensitivity);
		float upRight	= up-(tilt*tiltSensitivity);
		int liftPot = (leftLiftPotent.getHRCalibratedValue()-100) + (SensorValue[rightLiftPot]-400);
		float liftMult = 1.0;
		if (liftPot > 500) {
			liftPot-=500;
			liftMult = 1.0-(liftPot/2200);
			liftMult = liftMult < 0.4 ? 0.4 : liftMult;
		}

		if (nChangeButton != changeButton && nChangeButton) {
			direction *= -1;
		}

		if (nFlyWheelToggleB != flyWheelToggleB && nFlyWheelToggleB) {
			flyWheelToggle = !flyWheelToggle;
		}

		leftDrive.setSpeed(left*liftMult);
		rightDrive.setSpeed(right*liftMult);
		intake.setSpeed(intakeButton.getPressed()*127);
		motor[intakeMotor] = intake*127;
		motor[flyWheel] = flyWheelToggle*flyWheelSpeed;
		//setLeftDriveSpeed(left);
		//setRightDriveSpeed(right);
		motor[leftLift] = upLeft;
		motor[rightLift] = upRight;
		motor[turnTable] = turnTblSpeed;
		setLCDPosition(0,0);
		displayNextLCDNumber(getMotorEncoder(leftSide1));
		setLCDPosition(1,0);
		displayNextLCDNumber(getMotorEncoder(rightSide1));
		changeButton = nChangeButton;
		flyWheelToggleB = nFlyWheelToggleB;
		if (turnTblButtonPrev != turnTblButton && turnTblButton != 0) {	//If the turntable button was just pressed
			clearTimer(0);
		}
		if (turnTblButton != 0) {
			if (time100[0] < 5) {
				turnTblSpeed = 30*turnTblButton;
			} else {
				turnTblSpeed = 127*turnTblButton;
			}
		} else {
			turnTblSpeed = 0;
		}
		turnTblButtonPrev = turnTblButton;
	}
}
