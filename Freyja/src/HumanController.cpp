#include "HumanController.h"
#include <iostream>
#include <stdio.h>
using namespace std;

HumanController::HumanController(Robot *robotPointer) :
		moveJoystick((uint32_t) PORT_SPEED), turnJoystick((uint32_t) PORT_TURN),
		operatorJoystick((uint32_t) PORT_OPERATOR), robotPointer(robotPointer) {

}

void HumanController::update() {
	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	if(moveJoystick.GetRawButton(1)) {
		robotPointer->changeDrivetrainStateToHighSpeed();
	}
	if(turnJoystick.GetRawButton(1)) {
		robotPointer->changeDrivetrainStateToPRECISION_TRIGGER();
	}
	if(turnJoystick.GetRawButton(2)) {
		robotPointer->changeDrivetrainStateToBrake();
	}
	if(operatorJoystick.GetRawButton(2)) {
		robotPointer->changePistonState(Arm::PistonState::EXTENDING);
	}
	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::RETRACTING);
	}
	if(operatorJoystick.GetRawButton(6)) {
		robotPointer->changeCompressorState(Arm::CompressorState::OFF);
	}
	if(operatorJoystick.GetRawButton(7)) {
		robotPointer->changeCompressorState(Arm::CompressorState::ON);

	}

	//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	// MAKE CONSTANT
	//XXXXXXXXXXXXXXXXXX
	//Lifter Controls
	if(robotPointer->getLifterState() == Lifter::State::MOVING || operatorJoystick.GetY() * operatorJoystick.GetY() > 0.04) {
		robotPointer->setLifter(operatorJoystick.GetY());
	}

	//this moves the lifter up by one level
	if (operatorJoystick.GetRawButton(11) && robotPointer->getLifterState() != Lifter::State::AUTO_LIFTING) {
	 robotPointer->liftDist(TOTE_HEIGHT);
	 }
	 //this moves the lifter down by one level
	 if (operatorJoystick.GetRawButton(10) && robotPointer->getLifterState() != Lifter::State::AUTO_LIFTING) {
	 robotPointer->liftDist(-TOTE_HEIGHT);
	 }
	 //this moves the lifter to the lowest level
	 if (operatorJoystick.GetRawButton(9)) {
	 robotPointer -> zeroLifter();
	 }
}
