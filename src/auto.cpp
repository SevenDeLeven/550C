/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */
#include "main.h"
#include "auto.h"
#include "portConfig.h"
const char* autonomousNames[] = {"Blue Flag", "Red Flag", "Blue Cap", "Red Cap", "Skills"};

int s_autonomousNames = 5;

bool ranPreAuton = false;

const char* getAutonName() {
	if (auton == 0){
		return "Auton 1";
	} else if (auton == 1) {
		return "Auton 2";
	} else if (auton == 2) {
		return "Auton 3";
	} else if (auton == 3) {
		return "Auton 4";
	} else if (auton == 4) {
		return "Auton 5";
	} else if (auton < 0) {
		return "Auton < 0 ERR";
	} else {
		return "Auton > 4 ERR";
	}
}
