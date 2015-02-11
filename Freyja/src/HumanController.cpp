#include "HumanController.h"
#include <iostream>
#include <stdio.h>
using namespace std;

/** Controller constructor, initializes fields */
HumanController::HumanController(Robot *robot) :
		//Initializes joysticks to appropriate ports
		//Robot pointer initialized to parameter pointer
		moveJoystick((uint32_t) PORT_SPEED), turnJoystick((uint32_t) PORT_TURN), operatorJoystick((uint32_t) PORT_OPERATOR), robotPointer(robot) {
}

/** Updates this human controller */
void HumanController::update() {
	//Sends movement command to robot drivetrain wrapper method based on joystick values
	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	//Various button tests and resulting commands
	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::EXTENDING);
	}
	if (operatorJoystick.GetRawButton(1)) {
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
	if (operatorJoystick.GetRawButton(7)) {
		robotPointer->setLifterLevel(robotPointer->getLevel() + 1);
	}
	//this moves the lifter down by one level
	if (operatorJoystick.GetRawButton(8)) {
		robotPointer->setLifterLevel(robotPointer->getLevel() - 1);
	}
	//this moves the lifter to the lowest level
	if (operatorJoystick.GetRawButton(10)) {
		robotPointer->zeroLifter();
	}
}
