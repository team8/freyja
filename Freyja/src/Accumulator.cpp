#include "Accumulator.h"
#include "Constants.h"
#include <iostream>

Accumulator::Accumulator() :
	solenoid((uint32_t) ACCUMULATOR_SOLENOID_1_PORT_A, ACCUMULATOR_SOLENOID_1_PORT_B),
	leftVic((uint32_t) PORT_ACCUMULATE_LEFT_VIC),
	rightVic((uint32_t) PORT_ACCUMULATE_RIGHT_VIC),
	timer(), ejectSpeed(), vicSpeed(), leftSpinningSpeed(), rightSpinningSpeed(), openPiston()
{
wheelState = WheelState::IDLE;
pistonState = PistonState::IDLE;
openPiston = true;
}

void Accumulator::setPistonState(PistonState state) {
	this->pistonState = state;
	this->timer.Start();
}

void Accumulator::setWheelState(WheelState state) {
	this->wheelState = state;
}

void Accumulator::eject() {
	setWheelState(WheelState::EJECTING);
}

void Accumulator::accumulate() {
	setWheelState(WheelState::ACCUMULATING);
}


void Accumulator::update() {
	std::cout << "Piston State: " << (int)pistonState << std::endl;
	//std::cout << "Wheel State: " << (int)wheelState << std::endl;


	switch(pistonState) {
	case PistonState::EXTENDING:
		openPiston = false;
		solenoid.Set(DoubleSolenoid::Value::kForward);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = PistonState::IDLE;
		}
		break;
	case PistonState::RETRACTING:
		openPiston = true;
		solenoid.Set(DoubleSolenoid::Value::kReverse);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = PistonState::IDLE;
		}
		break;
	case PistonState::IDLE:
		solenoid.Set(DoubleSolenoid::Value::kOff);
		timer.Stop();
		timer.Reset();
		break;
	default:
		setPistonState(PistonState::IDLE);
		break;
	}
	switch(wheelState) {
	case WheelState::ACCUMULATING:
		leftVic.Set(0.5);
		rightVic.Set(0.5);
		break;
	case WheelState::IDLE:
		leftVic.Set(0);
		rightVic.Set(0);
		break;
	case WheelState::EJECTING:
		leftVic.Set(-0.5);
		rightVic.Set(-0.5);
		break;
	case WheelState::SPINNING:
		leftVic.Set(0.5);
		rightVic.Set(-0.5);
		break;
	default:
		setWheelState(WheelState::IDLE);
		break;
	}
}

void Accumulator::togglePiston() {
	std::cout << "CALLING TOGGLE PISTON" << std::endl;
	if(pistonState == PistonState::IDLE) {
		if(openPiston) {
			setPistonState(PistonState::EXTENDING);
			std::cout << "Extending Accumulator" << std::endl;
			//openPiston = false;
		}
		else {
			setPistonState(PistonState::RETRACTING);
			std::cout << "Retracting Accumulator" << std::endl;
			//openPiston = true;
		}
	}
}

void Accumulator::disable() {
	setPistonState(PistonState::IDLE);
	setWheelState(WheelState::IDLE);
}

void Accumulator::init() {
	setPistonState(PistonState::IDLE);
	setWheelState(WheelState::IDLE);
	setPistonState(PistonState::EXTENDING);
}

Accumulator::~Accumulator() {
}
