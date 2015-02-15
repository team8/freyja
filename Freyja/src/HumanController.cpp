#include "HumanController.h"
#include <iostream>
#include <stdio.h>
using namespace std;

HumanController::HumanController(Robot *robot) :
		/* Initializes joysticks to appropriate ports
		 * Robot pointer initialized to parameter */
		moveJoystick((uint32_t) PORT_SPEED), turnJoystick((uint32_t) PORT_TURN),
		operatorJoystick((uint32_t) PORT_OPERATOR), robotPointer(robot) {
}

/** Relays commands based on joystick input to the subsystems using the robot pointer */
void HumanController::update() {
	//DRIVETRAIN CONTROLS
	//Moves the robot based on joystick values
	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	//ARM CONTROLS
	//Starts extending the piston
	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::EXTENDING);
	}
	//Starts retracting the piston
	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::RETRACTING);
	}
	//Turns the compressor off
	if(operatorJoystick.GetRawButton(6)) {
		robotPointer->changeCompressorState(Arm::CompressorState::OFF);
	}
	//Turns the compressor on
	if(operatorJoystick.GetRawButton(7)) {
		robotPointer->changeCompressorState(Arm::CompressorState::ON);
	}

	//LIFTER CONTROLS
	//this moves the lifter up by one level
	if(operatorJoystick.GetRawButton(7)) {
		robotPointer->setLifterLevel(robotPointer->getLevel() + 1);
	}
	//this moves the lifter down by one level
	if(operatorJoystick.GetRawButton(8)) {
		robotPointer->setLifterLevel(robotPointer->getLevel() - 1);
	}
	//this moves the lifter to the lowest level (zeroes the lifter)
	if(operatorJoystick.GetRawButton(10)) {
		robotPointer->zeroLifter();
	}
}
