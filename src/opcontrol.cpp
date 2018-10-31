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
#include "converter.h"
#include "timers.h"
#include "portConfig.h"

float tiltSensitivity = 0.75;

void operatorControl() {
	JoystickButtonGroup intakeButton(1, 5);
	JoystickButtonGroup turnTableButton(1, 6);
	JoystickToggleButton directionButton(1, 7, JOY_DOWN);
	JoystickToggleButton flyWheelButton(1, 8, JOY_DOWN);

	JoystickAnalog forwardAxis(1, 3);
	JoystickAnalog turnAxis(1, 4);
	JoystickAnalog liftAxis(1, 2);
	JoystickAnalog liftTiltAxis(1, 1);

	Timer turnTableTimer;

	while (true) {
		directionButton.update();
		flyWheelButton.update();
		intakeButton.update();
		turnTableButton.update();

		float forw 		= forwardAxis.getValue() * (directionButton.getToggled() ? -1 : 1);
		float turn		= turnAxis.getValue();
		float left 		= forw + turn;
		float right 	= forw - turn;
		int up = liftAxis.getValue();
		int tilt = liftTiltAxis.getValue();
		float upLeft	= up+(tilt*tiltSensitivity);
		float upRight	= up-(tilt*tiltSensitivity);
		int liftPot = (leftLiftPotent.getCalibratedValue()) + (rightLiftPotent.getCalibratedValue());
		float liftMult = 1.0;
		if (liftPot > 500) {
			liftPot-=500;
			liftMult = 1.0-(liftPot/2200);
			liftMult = liftMult < 0.4 ? 0.4 : liftMult;
		}

		leftDrive.setSpeed(left*liftMult);
		rightDrive.setSpeed(right*liftMult);
		intake.setSpeed(intakeButton.getTotal()*127);
		flyWheel.setSpeed(flyWheelButton.getToggled()*127);
		//setLeftDriveSpeed(left);
		//setRightDriveSpeed(right);
		leftLift.setSpeed(upLeft);
		rightLift.setSpeed(upRight);
		lcd.setLine(1, convertIntToString(leftIME.getDistance()));
		lcd.setLine(2, convertIntToString(rightIME.getDistance()));
		if (turnTableButton.getPressed()) {	//If the turntable button was just pressed
			turnTableTimer.resetTimer();
		}
		if (turnTableButton.getTotal() != 0) {
			if (turnTableTimer.getTimeMillis() < 500) {
				turnTable.setSpeed(127*turnTableButton.getTotal());
			} else {
				turnTable.setSpeed(127*turnTableButton.getTotal());
			}
		} else {
			turnTable.setSpeed(0);
		}
	}
}
