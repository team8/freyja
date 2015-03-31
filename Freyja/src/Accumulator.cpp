#include "Accumulator.h"
#include "Constants.h"


Accumulator::Accumulator() :
	solenoid((uint32_t) ACCUMULATOR_SOLENOID_1_PORT_A, ACCUMULATOR_SOLENOID_1_PORT_B),
	solenoid2((uint32_t) ACCUMULATOR_SOLENOID_2_PORT_A, ACCUMULATOR_SOLENOID_2_PORT_B),
	leftVic((uint32_t) PORT_ACCUMULATE_LEFT_VIC),
	rightVic((uint32_t) PORT_ACCUMULATE_RIGHT_VIC)
{
setPistonState(PistonState::IDLE);
setWheelState(WheelState::IDLE);
openPiston = true;
ejectSpeed = 0.1;
vicSpeed = 0.1;
leftSpinningSpeed = 0.1;
rightSpinningSpeed = 0.1;
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
	switch(pistonState) {
	case PistonState::EXTENDING:
		openPiston = true;
		solenoid.Set(DoubleSolenoid::Value::kForward);
		solenoid2.Set(DoubleSolenoid::Value::kForward);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = PistonState::IDLE;
		}
		break;
	case PistonState::RETRACTING:
		openPiston = false;
		solenoid.Set(DoubleSolenoid::Value::kReverse);
		solenoid2.Set(DoubleSolenoid::Value::kReverse);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = PistonState::IDLE;
		}
		break;
	case PistonState::SPINNING:
		solenoid.Set(DoubleSolenoid::Value::kForward);
		solenoid2.Set(DoubleSolenoid::Value::kReverse);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = PistonState::IDLE;
		}
		break;
	case PistonState::IDLE:
		solenoid.Set(DoubleSolenoid::Value::kOff);
		solenoid2.Set(DoubleSolenoid::Value::kOff);
		timer.Stop();
		timer.Reset();
		break;
	default:
		setPistonState(PistonState::IDLE);
		break;
	}
	switch(wheelState) {
	case WheelState::ACCUMULATING:
		leftVic.Set(vicSpeed);
		rightVic.Set(-vicSpeed);
		break;
	case WheelState::IDLE:
		leftVic.Set(0);
		rightVic.Set(0);
		break;
	case WheelState::EJECTING:
		leftVic.Set(-ejectSpeed);
		rightVic.Set(ejectSpeed);
		break;
	case WheelState::SPINNING:
		leftVic.Set(leftSpinningSpeed);
		rightVic.Set(-rightSpinningSpeed);
		break;
	default:
		setWheelState(WheelState::IDLE);
		break;
	}
}

void Accumulator::togglePiston() {
	if(openPiston) {
		setPistonState(PistonState::RETRACTING);
	}
	else {
		setPistonState(PistonState::EXTENDING);
	}
}

void Accumulator::disable() {
	setPistonState(PistonState::IDLE);
	setWheelState(WheelState::IDLE);
}

void Accumulator::init() {
	setPistonState(PistonState::IDLE);
	setWheelState(WheelState::IDLE);
}

Accumulator::~Accumulator() {
}
