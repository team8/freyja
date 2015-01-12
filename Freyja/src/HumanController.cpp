/*
 * HumanController.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#include "HumanController.h"

HumanController::HumanController() :
	moveJoystick(PORT_SPEED),
	turnJoystick(PORT_TURN)
	{

	}

void HumanController::update(Robot *robotPointer) {
	robotPointer -> move(moveJoystick.GetY(),turnJoystick.GetX());
}
