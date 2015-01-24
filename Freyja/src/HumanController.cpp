#include "HumanController.h"

HumanController::HumanController(Robot *robotPointer) :
	moveJoystick((uint32_t)PORT_SPEED),
	turnJoystick((uint32_t)PORT_TURN),
	operatorJoystick((uint32_t) PORT_OPERATOR)
{
	this->robot = robotPointer;
}

void HumanController::update() {
	robot->move(moveJoystick.GetY(),turnJoystick.GetX());

	if(operatorJoystick.GetRawButton(1)) {
		robot->changeArmState(Arm::State::EXTENDING);
	}

	if(operatorJoystick.GetRawButton(2)) {
		robot->changeArmState(Arm::State::RETRACTING);
	}

	if(operatorJoystick.GetRawButton(3)) {
		robot->changeArmState(Arm::State::IDLE);
	}

	if(operatorJoystick.GetRawButton(4)) {
		robot->changeArmState(Arm::State::OFF);
	}

	//robot->changeArmState(operatorJoystick.GetRawButton());
}
