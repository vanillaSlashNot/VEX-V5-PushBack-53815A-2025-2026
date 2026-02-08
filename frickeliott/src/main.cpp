#include "main.h"

// ----------------------------------------------------------------------------
// LightHouse Studios Robotics
// Hsi mom im on camera!!! :DDDD -Elliott
// ----------------------------------------------------------------------------











// -----------------------------------------------------------------------------
// Start ups / initilaze
// -----------------------------------------------------------------------------
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(0, "LightHouse Robotics");
	pros::lcd::set_text(1, "Alliance Color");
	pros::lcd::set_text(2, "Auton Side");
	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn2_cb(on_right_button);
}

// -----------------------------------------------------------------------------
// Disabled  Initialization
// -----------------------------------------------------------------------------
void disabled() {}
void competition_initialize() {}












// -----------------------------------------------------------------------------
// Robot driver Control
// -----------------------------------------------------------------------------
void opcontrol() {


	while (true) {
		// Arcade drive
		int power = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_RIGHT_X);
		int stafeDrive = master.get_analog(ANALOG_LEFT_X);
		leftDrive.move(power + turn);
		rightDrive.move(power - turn);

		// Strafeing control 
		if (master.get_digital(DIGITAL_X)) {
			strafe.move(strafeSpeed);
		} else if (master.get_digital(DIGITAL_B)) {
			strafe.move(-strafeSpeed);
		} else {
			strafe.move(0);
		}

		// Intake control (L1 / L2)
		if (master.get_digital(DIGITAL_L1)) {
			intake.move(intakeSpeed);
			pros::lcd::set_text(3, "Intake Forward");
		} else if (master.get_digital(DIGITAL_L2)) {
			intake.move(-intakeSpeed);
			pros::lcd::set_text(3, "Intake Reverse");
		} else {
			intake.move(0);
		}


	
	//	pros::delay(20);
	}
}

