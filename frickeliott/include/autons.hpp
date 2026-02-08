// -----------------------------------------------------------------------------
// callback things for screen buttons
// -----------------------------------------------------------------------------



//int autonColor = 1; // 1 = Blue, -1 = Red
//int autonSide = 1;  // 1 = Right, -1 = Left

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