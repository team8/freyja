#include "Arm.h"


Arm::Arm():
	compressor(),
	solenoid((uint32_t) 0, (uint32_t) 1)
{
	setState(IDLE);
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

void Arm::setState(State state) {
	this -> state = state;
}

void Arm::disable() {
	setState(IDLE);
}

void Arm::update() {

	//There are a couple of semantic errors with this code, first off, you can't actually start compressing... Also, you can't compress and do something else at the same time
	//If you were able to compress while the user is extending or retracting that would be extremely useful
	switch(state) {
	case EXTENDING:
		solenoid.Set(DoubleSolenoid::Value::kForward);
		break;
	case RETRACTING:
		solenoid.Set(DoubleSolenoid::Value::kReverse);
		break;
	case IDLE:
		solenoid.Set(DoubleSolenoid::Value::kOff);
		break;
	case OFF:
		compressor.Stop();
		break;
	}
}

void Arm::init() {
	setState(IDLE);
}
