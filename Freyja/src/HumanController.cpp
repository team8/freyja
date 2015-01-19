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

	if(operatorJoystick.GetRawButton(1)){
		robotPointer -> changeArmState(EXTENDING)
	}
	if(operatorJoystick.GetRawButton(2)){
		robotPointer -> changeArmState(RETRACTING)
	}
	if(operatorJoystick.GetRawButton(3)){
		robotPointer -> changeArmState(IDLE)
	}
	if(operatorJoystick.GetRawButton(4)){
		robotPointer -> changeArmState(OFF)
	}
	//robotPointer -> changeArmState(operatorJoystick.GetRawButton());
}
