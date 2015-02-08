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

	//this moves the lifter up by one level
	if(operatorJoystick.GetRawButton(7)) {
		robotPointer -> setLifterLevel(robotPointer -> getLevel() + 1);
	}
	//this moves the lifter down by one level
	if(operatorJoystick.GetRawButton(8)) {
		robotPointer -> setLifterLevel(robotPointer -> getLevel() - 1);
	}
	//this moves the lifter to the lowest level
	if(operatorJoystick.GetRawButton(10)) {
		robotPointer -> zeroLifter();
	}
}
