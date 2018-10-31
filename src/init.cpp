/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include <vector>
#include "main.h"
#include "auto.h"
#include "portConfig.h"
/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {

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
void initialize() {
  lcd = LCD(uart1);
  if (imeInitializeAll() != 2) {

  }
  lcd.clearLCD();
	bool rightPressedPrev = false;
	bool leftPressedPrev = false;
	bool centerPressedPrev = false;
	bool changedLCD = true;

	while (!isEnabled()) {
		bool rightPressed = lcd.getRightButtonPressed();
		bool leftPressed = lcd.getLeftButtonPressed();
		bool centerPressed = lcd.getCenterButtonPressed();
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
		}
		if (changedLCD) {
			lcd.clearLine(0);
			lcd.setLine(0, getAutonName());
			lcd.clearLine(1);
      lcd.setLine(1, autonomousNames[auton]);
		}
		rightPressedPrev = rightPressed;
		leftPressedPrev = leftPressed;
		centerPressedPrev = centerPressed;
		changedLCD = false;
	}
}
