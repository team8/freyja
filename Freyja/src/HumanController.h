#ifndef HUMAN_CONTROLLER_H
#define HUMAN_CONTROLLER_H

#include <WPILib.h>
#include "Constants.h"
#include "Robot.h"

class HumanController {
private:
	Joystick moveJoystick;
	Joystick turnJoystick;
	Joystick operatorJoystick;
	
public:
	HumanController();
	void update(Robot *robotPointer);
};

#endif
