#include "main.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motor setup
pros::MotorGroup leftDrive({-10, -8, -9});
pros::MotorGroup rightDrive({1, 3, 2});
pros::Motor intake(11);
pros::Motor strafe(-16);
pros::ADIDigitalOut clamp('H', LOW);

int intakeSpeed = 127;
int strafeSpeed = 100;
pros::lcd::set_text(0, "Operator Control Active");