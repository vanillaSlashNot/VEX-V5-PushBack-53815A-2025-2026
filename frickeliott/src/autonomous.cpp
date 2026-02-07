// -----------------------------------------------------------------------------
// Auton
// -----------------------------------------------------------------------------
void autonomous() {
	pros::lcd::set_text(3, "Autonomous Started!");

	// Motor groups for autonomous
	pros::MotorGroup leftDrive({-10, -8, -9});   // reversed left motors
	pros::MotorGroup rightDrive({1, 3, 2});      // right motors
	pros::Motor intake(11);
	pros::Motor strafe(-16);
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