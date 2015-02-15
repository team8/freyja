#ifndef HUMAN_CONTROLLER_H
#define HUMAN_CONTROLLER_H

#include <WPILib.h>
#include "Constants.h"
#include "Robot.h"

/**
 * The class representing the human controller
 * This class takes human input through joysticks
 * and sends appropriate commands to the robot
 */
class HumanController {
private:
	//The joystick for forward-backward motion
	Joystick moveJoystick;
	//The joystick for rotation
	Joystick turnJoystick;
	//The joystick for non-drivetrain functions
	Joystick operatorJoystick;
	//The robot pointer through which commands are sent
	Robot *robotPointer;
public:
	HumanController(Robot *robotPointer);
	void update();
};

#endif
