/*
 * HumanController.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#include "HumanController.h"

HumanController::HumanController() :
	moveJoystick((uint32_t)PORT_SPEED),
	turnJoystick((uint32_t)PORT_TURN),
	operatorJoystick((uint32_t) PORT_OPERATOR)
	{

	}

void HumanController::update(Robot *robotPointer) {
	robotPointer -> move(moveJoystick.GetY(),turnJoystick.GetX());
	robotPointer -> changeArmState(operatorJoyStick.getRawButton());
}
