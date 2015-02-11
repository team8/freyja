#ifndef HUMAN_CONTROLLER_H
#define HUMAN_CONTROLLER_H

#include <WPILib.h>
#include "Constants.h"
#include "Robot.h"

/**
 * The class representing the human controller
 * This class is responsible for getting human input and sending appropriate command to the robot
 */
class HumanController {
private:
	/** The joystick for forward-backward motion */
	Joystick moveJoystick;
	/** The joystick for rotation motion */
	Joystick turnJoystick;
	/** The joystick for the superstructure */
	Joystick operatorJoystick;
	
	/** The robot pointer through which commands are sent */
	Robot *robotPointer;
public:
	/** Controller constructor, initializes fields */
	HumanController(Robot *robotPointer);
	/** Updates this human controller */
	void update();
};

#endif
