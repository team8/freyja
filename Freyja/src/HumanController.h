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
	
	Robot *robot;

public:
	HumanController(Robot *robotPointer);
	void update();
};

#endif /* HUMAN_CONTROLLER_H */
