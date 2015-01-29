#include "Arm.h"

Arm::Arm() :
		compressor(), solenoid((uint32_t) 0, (uint32_t) 1) {
	compressor.Start();
	setPistonState(IDLE);
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

void Arm::setCompressorState(CompressorState state) {
	this->compressorState = state;
}
void Arm::setPistonState(PistonState state) {
	this->pistonState = state;
}

void Arm::disable() {
	setCompressorState(OFF);
	setPistonState(IDLE);
}

void Arm::update() {

	//There are a couple of semantic errors with this code, first off, you can't actually start compressing... Also, you can't compress and do something else at the same time
	//If you were able to compress while the user is extending or retracting that would be extremely useful

	//I understand that you can't actually start compressing, and I will add that.
	//As for whether we can compress and extend and retract at the same time, I think we can do that, as long as we hook the
	//Compressor up to tanks and then to the solenoid. This will allow for a more stable air pressure, since all the compressor
	//does is pressurize air, the only issue with extending and compressing at the same time is that we lose all the compressed air,
	//so if we can have valves that open and close we should be fine to do this at the same time.

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
	}
	switch(compressorState) {
	case ON:
		compressor.Start();
		break;
	case OFF:
		compressor.Stop();
		break;
	}
}

void Arm::init() {
	setCompressorState(ON);
	setPistonState(IDLE);
}
