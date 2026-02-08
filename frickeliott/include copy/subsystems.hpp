#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

extern pros::adi::DigitalOut led_disabled('B');
extern pros::adi::DigitalOut led_IS1_jammed('C');
extern pros::adi::DigitalOut led_placeholder('D');
inline pros::adi::DigitalIn limitS_outtake('A');

