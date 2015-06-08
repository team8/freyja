#include "HumanController.h"
#include <iostream>
#include <stdio.h>
using namespace std;

HumanController::HumanController(Robot *robotPointer) :
		moveJoystick((uint32_t) PORT_SPEED), turnJoystick((uint32_t) PORT_TURN),
		operatorJoystick((uint32_t) PORT_OPERATOR), robotPointer(robotPointer) {

}

void HumanController::update() {
	// Move Stick
	// Coordinate Direction - Driving
	// 1 (Trigger) - High Speed

	robotPointer->move(moveJoystick.GetY(), turnJoystick.GetX());

	if(moveJoystick.GetRawButton(6)) {
		robotPointer->changeDrivetrainStateToBrake();
	}
	if(moveJoystick.GetRawButton(7)) {
		robotPointer->changeDrivetrainStateToBrake();
	}

	// Turn Stick
	// 1 (Trigger) - Precision
	// 2 (Brake) - Brakes, not functional
	if(turnJoystick.GetRawButton(1)) {
		robotPointer->changeDrivetrainStateToTrigger();
	}
	if(turnJoystick.GetRawButton(2)) {
		robotPointer->changeDrivetrainStateToBrake();
	}

	// Operator Stick
	//
	// Lifter Controls
	// Y-Axis - Lifter
	// 1 (Trigger) - Toggle Accumulator
	// 2 (Large Center) - Toggle Arm
	// 3 (Small Center) - The spin
	// 4 (Left Top) - Accumulate
	// 5 (Right Top - Eject
	// 6 (Left Upper) - Stop Compressing
	// 7 (Left Lower) - Start Compressing
	// 9 (Odd Bottom) - Zero Lifter
	// 10 (Right Lower) - Lower Level
	// 11 (Right Upper) - Raise Level
	if(robotPointer->getLifterState() == Lifter::State::MOVING || std::abs(operatorJoystick.GetY())  > 0.1) {
		robotPointer->setLifter(operatorJoystick.GetY());
	}
	if(std::abs(operatorJoystick.GetY()) < 0.05) {
		robotPointer->idleLifter();
	}
	if(operatorJoystick.GetRawButton(1)) {
		robotPointer->toggleArm();
	}
	// ACCUMULATOR CONTROLS
	if(moveJoystick.GetRawButton(5)) {
		robotPointer->toggleAccumulator();
	}
	if(!moveJoystick.GetRawButton(3) && !moveJoystick.GetRawButton(4) && !moveJoystick.GetRawButton(2)) {
		robotPointer->changeWheelState(Accumulator::WheelState::IDLE);
	}
	if(moveJoystick.GetRawButton(4)) {
		robotPointer->changeWheelState(Accumulator::WheelState::SPINNING);
	}
	if(moveJoystick.GetRawButton(2)) {
		robotPointer->changeWheelState(Accumulator::WheelState::EJECTING);
	}
	if(moveJoystick.GetRawButton(3)) {
		robotPointer->changeWheelState(Accumulator::WheelState::ACCUMULATING);
	}
	//ARM CONTROLS
	if(operatorJoystick.GetRawButton(6)) {
		robotPointer->changeCompressorState(Arm::CompressorState::OFF);
	}
	if(operatorJoystick.GetRawButton(7)) {
		robotPointer->changeCompressorState(Arm::CompressorState::ON);
	}
	//LIFTER CONTROLS
	if(operatorJoystick.GetRawButton(8)) {
		robotPointer->resetLifterZero();
	}
	if (operatorJoystick.GetRawButton(9)) {
		robotPointer -> zeroLifter();
	}
	if(operatorJoystick.GetRawButton(10)) {
		robotPointer->changeDrivetrainStateToBrake();
	}
	if(operatorJoystick.GetRawButton(11)) {
		robotPointer->changeDrivetrainStateToBrake();
	}
}
