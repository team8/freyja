#include "HumanController.h"
#include <iostream>
#include <stdio.h>
using namespace std;

HumanController::HumanController() :
		moveJoystick((uint32_t) PORT_SPEED), turnJoystick((uint32_t) PORT_TURN), operatorJoystick((uint32_t) PORT_OPERATOR){
}

void HumanController::update(Robot *robotPointer) {
	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::EXTENDING);
	}
	if(operatorJoystick.GetRawButton(2)) {
		robotPointer->changePistonState(Arm::PistonState::RETRACTING);
	}
	if(operatorJoystick.GetRawButton(6)) {
		robotPointer->changeCompressorState(Arm::CompressorState::OFF);
	}
	if(operatorJoystick.GetRawButton(7)) {
		robotPointer->changeCompressorState(Arm::CompressorState::ON);
	}
	if(operatorJoystick.GetRawButton(3)) {
		robotPointer->changePistonState(Arm::PistonState::IDLE);
	}
}
