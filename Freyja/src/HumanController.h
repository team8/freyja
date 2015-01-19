/*
 * HumanController.h
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#ifndef FREYJA_SRC_HUMANCONTROLLER_H_
#define FREYJA_SRC_HUMANCONTROLLER_H_
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


#endif /* FREYJA_SRC_HUMANCONTROLLER_H_ */
