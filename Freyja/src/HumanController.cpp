#include "HumanController.h"
#include <iostream>
#include <stdio.h>
using namespace std;

HumanController::HumanController() :
		moveJoystick((uint32_t) PORT_SPEED),
		turnJoystick((uint32_t) PORT_TURN),
		operatorJoystick((uint32_t) PORT_OPERATOR)
{

}

void HumanController::update(Robot *robotPointer) {
	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	if(moveJoystick.GetRawButton(1)) {
		robotPointer->changeDrivetrainStateToBRAKE();
	}

	if (turnJoystick.GetRawButton(1)){
		robotPointer->changeDrivetrainStateToPRECISION_TRIGGER();
	}

	if (operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::EXTENDING);
	}
	if (operatorJoystick.GetRawButton(2)) {
		robotPointer->changePistonState(Arm::PistonState::RETRACTING);
	}
	if(operatorJoystick.GetRawButton(6)) {
		robotPointer->changeCompressorState(Arm::CompressorState::OFF);
	}
	if (operatorJoystick.GetRawButton(7)) {
		robotPointer->changeCompressorState(Arm::CompressorState::ON);
	}

	//Lifter Controls

	//this moves the lifter up by one level
/*	if (operatorJoystick.GetRawButton(7)) {
		robotPointer->setLifterLevel(robotPointer->getLevel() + 1);
	}
	//this moves the lifter down by one level
	if (operatorJoystick.GetRawButton(8)) {
		robotPointer->setLifterLevel(robotPointer->getLevel() - 1);
	}
	//this moves the lifter to the lowest level
	if (operatorJoystick.GetRawButton(10)) {
		robotPointer -> zeroLifter();
	}*/
	
	robotPointer->setLifter(operatorJoystick.GetY());
}
