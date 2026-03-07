#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

//inline Drive chassis;



// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

inline pros::adi::DigitalOut led_disabledMode('B');
inline pros::adi::DigitalOut led_IS1_jammed('C');
inline pros::adi::DigitalOut led_placeholder('D');
inline pros::adi::DigitalOut led_disabledMode('B');
inline pros::adi::DigitalOut led_IS1_jammed('C');
inline pros::adi::DigitalOut led_placeholder('D');
inline pros::adi::DigitalIn limitS_outtake('A');

inline ez::PID liftPID{0.45, 0, 0, 0, "chassisPID"};
