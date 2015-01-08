/*
 * HumanController.h
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#ifndef FREYJA_SRC_HUMANCONTROLLER_H_
#define FREYJA_SRC_HUMANCONTROLLER_H_
#include <WPIlib.h>

class HumanController {
public:
	HumanController();
	virtual ~HumanController();
	void update(Robot *robotPointer);
private:

	Joystick moveJoystick;
	Joystick turnJoystick;
	Joystick operatorJoystick;
};

#endif /* FREYJA_SRC_HUMANCONTROLLER_H_ */
