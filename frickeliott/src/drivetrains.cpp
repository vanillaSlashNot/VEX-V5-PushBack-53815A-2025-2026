#include "main.h"

// Field-centric H-drive implementation for EZ-Template
// NOTE: Replace the motor ports below with the correct ports for your robot.

#include <cmath>
#include <algorithm>

// H-drive motor port constants (set these to your real ports).
// I leave them as 0 so you can fill them later without me guessing.
constexpr int EAST_PORT = 0;
constexpr int WEST_PORT = 0;
constexpr int NORTH_PORT = 0;
constexpr int SOUTH_PORT = 0;


static int limitMotor(double v) {
	if (v > 127.0) return 127;
	if (v < -127.0) return -127;
	return (int)std::round(v);
}

static int log_drive(int in) {
	// A simple expo/cubic curve to give finer low-speed control.
	// Input: -127..127, Output: -127..127
	double d = (double)in / 127.0;
	double sign = d < 0 ? -1.0 : 1.0;
	double out = sign * std::pow(std::fabs(d), 1.5) * 127.0;
	return (int)std::round(out);
}

// Public function called from opcontrol to run field-centric drive for H-drive
void field_centric_opcontrol() {
	// Read joysticks
	int x_joy = log_drive(master.get_analog(ANALOG_LEFT_X));   // strafe intent
	int y_joy = log_drive(master.get_analog(ANALOG_LEFT_Y));   // forward/back intent
	int rotatey_joy = log_drive(master.get_analog(ANALOG_RIGHT_Y));
	int rotation = log_drive(master.get_analog(ANALOG_RIGHT_X)); // rotation (yaw)

	// Reset the IMU heading when UP is pressed (maps to Btn7U behavior)
	if (master.get_digital_new_press(DIGITAL_UP)) {
		chassis.drive_imu_reset(0);
	}

	// Compute vector magnitude and direction (degrees)
	double direction_vector = std::sqrt((double)x_joy * x_joy + (double)y_joy * y_joy);
	if (direction_vector > 127.0) direction_vector = 127.0;

	double direction_angle_deg = 0.0;
	if (direction_vector > 0.5) {
		// atan2(x, y) so 0 deg = forward (y positive), positive to the right
		direction_angle_deg = util::to_deg(std::atan2((double)x_joy, (double)y_joy));
	}

	// Get current heading from EZ-Template (degrees)
	double newNorth = chassis.drive_imu_get();

	// Compute drift between desired vector and robot heading
	double drive_drift_deg = direction_angle_deg - newNorth;

	// Convert drift to radians for cos/sin
	double drive_drift_rad = util::to_rad(drive_drift_deg);

	double cosX = std::cos(drive_drift_rad);
	double sinY = std::sin(drive_drift_rad);

	double driveX = direction_vector * cosX;   // strafe component
	double driveY = direction_vector * sinY;   // forward component

	// Motor outputs (map to your H-drive orientation). Adjust signs if necessary.
	int east_out = limitMotor(driveX + rotation);
	int west_out = limitMotor((driveX * -1.0) + rotation);
	int north_out = limitMotor((driveY * -1.0) + rotation);
	int south_out = limitMotor(driveY + rotation);

	east_drive.move(east_out);
	west_drive.move(west_out);
	north_drive.move(north_out);
	south_drive.move(south_out);
}
