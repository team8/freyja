#include "HumanController.h"

HumanController::HumanController(Robot *robot) :
		moveJoystick((uint32_t) PORT_SPEED), turnJoystick((uint32_t) PORT_TURN), operatorJoystick((uint32_t) PORT_OPERATOR), robotPointer(robot) {
}

void HumanController::update() {
	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->changePistonState(Arm::PistonState::EXTENDING);
	}
	if(operatorJoystick.GetRawButton(2)) {
		robotPointer->changePistonState(Arm::PistonState::RETRACTING);
	}
	if(operatorJoystick.GetRawButton(4)) {
		robotPointer->changeCompressorState(Arm::CompressorState::OFF);
	}
	if(operatorJoystick.GetRawButton(5)) {
		robotPointer->changeCompressorState(Arm::CompressorState::ON);
	}
	if(operatorJoystick.GetRawButton(3)) {
		robotPointer->changePistonState(Arm::PistonState::IDLE);
	}
	if(operatorJoystick.GetRawButton(6)) {
		robotPointer->changePistonState(Arm::PistonState::PUSH);
	}
	//Lifter Controls
	if(operatorJoystick.GetRawButton(11)) {
		robotPointer -> setLifterLevel(1);
	}

	if(operatorJoystick.GetRawButton(7)) {
		robotPointer -> setLifterLevel(2);
	}

	if(operatorJoystick.GetRawButton(8)) {
		robotPointer -> setLifterLevel(3);
	}

	if(operatorJoystick.GetRawButton(9)) {
		robotPointer -> setLifterLevel(4);
	}
//TODO I don't know what this method is supposed to represent since there isn't documentation in this class
//	if(operatorJoystick.GetRawButton(10)) {
//		robotPointer -> moveLifterDown();
//	}
}
