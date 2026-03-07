#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor intake(11);  // Make this number negative if you want to reverse the motor

void set_intake(int input);
void intake_opcontrol();
