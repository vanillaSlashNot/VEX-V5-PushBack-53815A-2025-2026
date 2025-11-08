#include "main.h"

// ----------------------------------------------------------------------------
// LightHouse Studios Robotics
// Hsi mom im on camera!!! :DDDD -Elliott
// ----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// callback things for screen buttons
// -----------------------------------------------------------------------------
int autonColor = 1; // 1 = Blue, -1 = Red
int autonSide = 1;  // 1 = Right, -1 = Left

void on_left_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		autonSide = -1;
		pros::lcd::set_text(2, "Left Auton");
	} else {
		pros::lcd::set_text(2, "Auton Side");
	}
}

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		autonColor = 1;
		pros::lcd::set_text(1, "Blue Auton");
	} else {
		autonColor = -1;
		pros::lcd::set_text(1, "Red Auton");
	}
}

void on_right_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		autonSide = 1;
		pros::lcd::set_text(2, "Right Auton");
	} else {
		pros::lcd::set_text(2, "Auton Side");
	}
}

// -----------------------------------------------------------------------------
// Start ups / initilazinf
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
// Disabled  Iniytilaization
// -----------------------------------------------------------------------------
void disabled() {}
void competition_initialize() {}

// -----------------------------------------------------------------------------
// Auton
// -----------------------------------------------------------------------------
void autonomous() {
	pros::lcd::set_text(3, "Autonomous Started!");

	// Motor groups for autonomous
	pros::MotorGroup leftDrive({-10, -8, -9});   // reversed left motors
	pros::MotorGroup rightDrive({1, 3, 2});      // right motors
	pros::Motor intake(11);
	pros::Motor strafe(16);
	pros::ADIDigitalOut clamp('H', LOW);

	int driveSpeed = 100;
	int turnSpeed = 100;
	int intakeSpeed = 127;
	int turnDir = 1;

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

// -----------------------------------------------------------------------------
// bobot driver Control
// -----------------------------------------------------------------------------
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// Motor setup thingi 
	pros::MotorGroup leftDrive({-10, -8, -9});
	pros::MotorGroup rightDrive({1, 3, 2});
	pros::Motor intake(11);
	pros::Motor strafe(16);
	pros::ADIDigitalOut clamp('H', LOW);

	int intakeSpeed = 127;
	int strafeSpeed = 100;

	pros::lcd::set_text(0, "Operator Control Active");

	while (true) {
		// Arcade drive
		int power = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_RIGHT_X);

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

	
		pros::delay(20);
	}
}

