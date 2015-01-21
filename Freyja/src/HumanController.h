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
