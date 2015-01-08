/*
 * HumanController.h
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#ifndef FREYJA_SRC_HUMANCONTROLLER_H_
#define FREYJA_SRC_HUMANCONTROLLER_H_

class HumanController {
public:
	HumanController(Robot *robotPointer);
	virtual ~HumanController();
	void update();
private:

	Joystick moveJoystick;
	Joystick turnJoystick;
	Joystick operatorJoystick;
};

#endif /* FREYJA_SRC_HUMANCONTROLLER_H_ */
