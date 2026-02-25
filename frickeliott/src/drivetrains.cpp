#include "main.h"

// Field-centric H-drive implementation for EZ-Template?


#include <cmath>
#include <algorithm>




static int limitMotor(double v) {
    // Clamps the value between -127 and 127 for PROS motor.move()
    return (int)std::clamp(v, -127.0, 127.0);
}

static int log_drive(int in) {
    double d = (double)in / 127.0;
    // Preservation of sign for the exponential curve
    double out = (d < 0 ? -1.0 : 1.0) * std::pow(std::fabs(d), 1.5) * 127.0;
    return (int)std::round(out);
}

void field_centric_opcontrol() {
    // 1. Get Inputs and apply curve
    int x_joy = log_drive(master.get_analog(ANALOG_LEFT_X)); 
    int y_joy = log_drive(master.get_analog(ANALOG_LEFT_Y));
    int turn  = log_drive(master.get_analog(ANALOG_RIGHT_X));


    // Reset heading if UP is pressed
    if (master.get_digital_new_press(DIGITAL_UP)) {
        chassis.drive_imu_reset(0);
    }

    // 2. Rotate the translation vector based on current IMU heading
    // EZ-Template heading is in degrees; convert to radians for math
    double heading_rad = util::to_rad(chassis.drive_imu_get());
    double cos_h = std::cos(heading_rad);
    double sin_h = std::sin(heading_rad);

    // Standard 2D rotation matrix:
    // Field-centric X/Y mapped to Robot-centric X/Y
    double driveX = x_joy * cos_h - y_joy * sin_h;
    double driveY = x_joy * sin_h + y_joy * cos_h;

    // 3. Command the Motor Groups
    // For H-Drive: Main rails handle Y-axis and Yaw (turning)
    // The H-center motors handle the X-axis (strafing)
    leftDrivet.move(limitMotor(driveY + turn));
    rightDrivet.move(limitMotor(driveY - turn));
    hDrivet.move(limitMotor(driveX));
}
