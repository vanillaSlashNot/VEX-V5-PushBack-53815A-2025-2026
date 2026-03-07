#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"



//drivedrain motor groups declaring. left -> H -> right
inline pros::MotorGroup leftDrivet({12, 11, 13}, pros::E_MOTOR_GEARSET_18, false);
inline pros::MotorGroup rightDrivet({-19, -20, -18}, pros::E_MOTOR_GEARSET_18, false):
inline pros::MotorGroup hDrivet({16, 15}, pros::E_MOTOR_GEARSET_36, false);

ez::tracking_wheel vert_trackerL({'E', 'F'}, 3.25, 8.25);   // This tracking wheel is parallel to the drive wheels
ez::tracking_wheel vert_trackerR({'G', 'H'}, 3.25, 8.25);   // This tracking wheel is parallel to the drive wheels
ez::tracking_wheel horiz_tracker({'C', 'D'}, 15, 3.25, 2);  // This tracking wheel is perpendicular to the drive wheels





// Chassis constructor
/*ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {2, 1, 3},     // Left Chassis Ports (negative port will reverse it!)
    {9, 8, 10},  // Right Chassis Ports (negative port will reverse it!)

    5,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    300  // Wheel RPM = cartridge * (motor gear / wheel gear)
); 
*/

// Uncomment the trackers you're using here!
// - `8` and `9` are smart ports (making these negative will reverse the sensor)
//  - you should get positive values on the encoders going FORWARD and RIGHT
// - `3.25` is the wheel diameter
// - `8.25` is the distance from the center of the wheel to the center of the robot
// ez::tracking_wheel horiz_tracker(8, 2.75, 4.0);  // This tracking wheel is perpendicular to the drive wheels
// ez::tracking_wheel vert_tracker(4, 3.25, 8.25);   // This tracking wheel is parallel to the drive wheels
// ez::tracking_wheel vert_tracker(4, 3.25, 8.25);   // This tracking wheel is parallel to the drive wheels


/*
inline pros::Motor left_front1{EAST_PORT, pros::E_MOTOR_GEARSET_06, false};
inline pros::Motor left_middle2{WEST_PORT, pros::E_MOTOR_GEARSET_06, false};
inline pros::Motor left_back3{NORTH_PORT, pros::E_MOTOR_GEARSET_06, false};
inline pros::Motor right_front4{SOUTH_PORT, pros::E_MOTOR_GEARSET_06, false};
inline pros::Motor right_middle5{SOUTH_PORT, pros::E_MOTOR_GEARSET_06, false};
inline pros::Motor right_back6{SOUTH_PORT, pros::E_MOTOR_GEARSET_06, false};
*/

