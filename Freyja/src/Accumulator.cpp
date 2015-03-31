#include "Accumulator.h"
#include "Constants.h"

Accumulator::Accumulator() :
	solenoid((uint32_t) SOLENOID_2_PORT_A, SOLENOID_2_PORT_B),
	leftVic((uint32_t) PORT_ACCUMULATE_LEFT_VIC),
	rightVic((uint32_t) PORT_ACCUMULATE_RIGHT_VIC)
{
setPistonState(IDLE);
this->wheelState = IDLE;
}

void Accumulator::setPistonState(PistonState state) {
	this->pistonState = state;
}

//Sets the target speed of the victors (note one vic is set to -speed)
void Accumulator::setVictors(double speed) {
	if(speed == 0) {
		state = IDLE;
	}
	state = ACCUMULATING;
	this->vicSpeed = speed;
}

void Accumulator::eject() {
	state = EJECTING;
	ejectSpeed = 0.1;
}


void Accumulator::update() {
	switch(pistonState) {
	case EXTENDING:
		solenoid.Set(DoubleSolenoid::Value::kForward);
		break;
	case RETRACTING:
		solenoid.Set(DoubleSolenoid::Value::kReverse);
		break;
	case IDLE:
		solenoid.Set(DoubleSolenoid::Value::kOff);
		break;
	default:
		setPistonState(IDLE);
		break;
	}
	switch(wheelState) {
	case ACCUMULATING:
		leftVic.Set(vicSpeed);
		rightVic.Set(-vicSpeed);
		break;
	case IDLE:
		leftVic.Set(0);
		rightVic.Set(0);
		break;
	case EJECTING:
		leftVic.Set(ejectSpeed);
		rightVic.Set(-ejectSpeed);
		break;
	default:
		this->wheelState = IDLE;
		break;
	}
}

void Accumulator::disable() {
	setPistonState(IDLE);
	this->wheelState = IDLE;
}

void Accumulator::init() {
	setPistonState(IDLE);
	this->wheelState = IDLE;
}
