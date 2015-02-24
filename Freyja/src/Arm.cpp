#include "Arm.h"
#include "Constants.h"


Arm::Arm() :
//Compressor which initializes the compressor with no arguments, and gives the solenoids their ports
	compressor(),
	solenoid1((uint32_t) SOLENOID_1_PORT_A, (uint32_t) SOLENOID_1_PORT_B)
	//solenoid2((uint32_t) SOLENOID_2_PORT_A, (uint32_t) SOLENOID_2_PORT_B)
{
	compressor.Start();
	setPistonState(IDLE);
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub, not sure what needs to be added here
}

void Arm::setCompressorState(CompressorState state) {
	//Simply changes the enum CompressorState. This method is called as a wrapping function in robot.
	this->compressorState = state;
}
void Arm::setPistonState(PistonState state) {
	//Does the same thing as setCompressorState, except changes the state of the piston
	this->pistonState = state;
}

bool Arm::getCompressor() {
	return true;
}
void Arm::disable() {
	//Turns everything off just in case
	setPistonState(IDLE);
	setCompressorState(OFF);
}

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
		break;
	case RETRACTING:
	//If the piston is retracting, it puts air in front of the disc, expelling the air out of the solenoid.
		solenoid1.Set(DoubleSolenoid::Value::kReverse);
		//solenoid2.Set(DoubleSolenoid::Value::kReverse);
		break;
	case IDLE:
	//Locks the solenoid, no actuation
		solenoid1.Set(DoubleSolenoid::Value::kOff);
		//solenoid2.Set(DoubleSolenoid::Value::kOff);
		break;
	case PUSH:
	//Pushes the piston a little.
		solenoid1.Set(DoubleSolenoid::Value::kForward);
		//solenoid2.Set(DoubleSolenoid::Value::kForward);
		//CHECK THIS VALUE LATER, it can still fully actuate possibly.
		Wait(0.2);
		setPistonState(IDLE);
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

void Arm::init() {
	//Turns everything off when we start the robot.
	setCompressorState(ON);
	setPistonState(IDLE);
}
