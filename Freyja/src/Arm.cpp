#include "Arm.h"
#include "Constants.h"

// A second comment

Arm::Arm() :
//Compressor which initializes the compressor with no arguments, and gives the solenoids their ports
		compressor(), solenoid1((uint32_t) SOLENOID_1_PORT_A,
				(uint32_t) SOLENOID_1_PORT_B),
		timer()
//solenoid2((uint32_t) SOLENOID_2_PORT_A, (uint32_t) SOLENOID_2_PORT_B)
{
	compressor.Start();
	pistonOpen = true;
	setPistonState(IDLE);
}
//Simply changes the enum CompressorState
void Arm::setCompressorState(CompressorState state) {
	this->compressorState = state;
}
//Changes the state of the piston
void Arm::setPistonState(PistonState state) {
	this->pistonState = state;
	this->timer.Start();
}
//TODO Why does this always return true?
bool Arm::getCompressor() {
	return true;
}
void Arm::disable() {
	setPistonState(IDLE);
	setCompressorState(OFF);
}
//Operates piston and compressor based on the states
void Arm::update() {
	//I understand that you can't actually start compressing, and I will add that.
	//As for whether we can compress and extend and retract at the same time, I think we can do that, as long as we hook the
	//Compressor up to tanks and then to the solenoid. This will allow for a more stable air pressure, since all the compressor
	//does is pressurize air, the only issue with extending and compressing at the same time is that we lose all the compressed air,
	//so if we can have valves that open and close we should be fine to do this at the same time.
	switch(pistonState) {
	case EXTENDING:
		//If the piston is extending, it puts air in the chamber behind the piston, pushing it forward
		solenoid1.Set(DoubleSolenoid::Value::kForward);
		//solenoid2.Set(DoubleSolenoid::Value::kForward);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = IDLE;
		}
		break;
	case RETRACTING:
		//If the piston is retracting, it puts air in front of the disc, expelling the air out of the solenoid.
		solenoid1.Set(DoubleSolenoid::Value::kReverse);
		//solenoid2.Set(DoubleSolenoid::Value::kReverse);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = IDLE;
		}
		break;
	case IDLE:
		//Locks the solenoid, no actuation
		solenoid1.Set(DoubleSolenoid::Value::kOff);
		//solenoid2.Set(DoubleSolenoid::Value::kOff);
		timer.Stop();
		timer.Reset();
		break;
	case PUSH:
		//Pushes the piston a little.
		solenoid1.Set(DoubleSolenoid::Value::kForward);
		//solenoid2.Set(DoubleSolenoid::Value::kForward);
		if(timer.Get() >= ARM_EXTEND_TIME) {
			timer.Stop();
			timer.Reset();
			pistonState = IDLE;
		}
		break;
	default:
		//In case stuff hits the fan
		setPistonState(IDLE);
		break;
	}

	switch(compressorState) {
	case ON:
		//Starts the compressor from an off state.
		compressor.Start();
		break;
	case OFF:
		//Turns the compressor Off
		compressor.Stop();
		break;
	default:
		//In case stuff hits the fan
		//setCompressorState(OFF);
		break;
	}
}

//Prepares arm for operation
void Arm::init() {
	setCompressorState(ON);
	setPistonState(PistonState::IDLE);
}

Arm::PistonState Arm::getPistonState() {
	return pistonState;
}

void Arm::toggleArm() {
	if(pistonState == PistonState::IDLE) {
		if(pistonOpen) {
			setPistonState(PistonState::EXTENDING);
			pistonOpen = false;
		}
		else {
			setPistonState(PistonState::RETRACTING);
			pistonOpen = true;
		}
	}
}

// Auto-generated destructor
Arm::~Arm() {
}
