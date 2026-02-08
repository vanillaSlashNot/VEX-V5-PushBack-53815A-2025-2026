#include "main.h"

void set_intake(int input) {
  intake.move(input);
}

void intake_opcontrol() {
  if (master.get_digital(DIGITAL_L1)) {
    set_intake(127);
  } 
  else if (master.get_digital(DIGITAL_L2)) {
    set_intake(-127);
  } 
  else {
    set_intake(0);
  }
}