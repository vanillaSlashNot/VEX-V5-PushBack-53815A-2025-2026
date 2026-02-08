#include "main.h"  

// -----------------------------------------------------------------------------
// Auto
// -----------------------------------------------------------------------------





void autonomous() {
	    pros::lcd::set_text(3, "Autonomous Started!");


	// swap directions for red or left auton
	if (autonColor == -1 && autonSide == -1) {
		turnDir = -1;
		pros::lcd::set_text(4, "Red Left Auton");
	} else if (autonColor == 1 && autonSide == 1) {
		pros::lcd::set_text(4, "Blue Right Auton");
	} else if (autonColor == -1 && autonSide == 1) {
		pros::lcd::set_text(4, "Red Right Auton");
	} else if (autonColor == 1 && autonSide == -1) {
		pros::lcd::set_text(4, "Blue Left Auton");
	}

	
}