#include "Lifter.h"
#include <iostream>
Lifter::Lifter() :
		victor((uint32_t) 9), liftEncoder((uint32_t) LIFT_ENCODER_PORT_A, (uint32_t) LIFT_ECONDER_PORT_B), digitalInput((uint32_t) LIMIT_SWITCH_TOP),
		digitalInput2((uint32_t) LIMIT_SWITCH_BOT), controller(0.f, 0.f, 0.f, &liftEncoder, &victor), state(IDLE),
		currentLevel() {
}

//Initializes lifter to be ready to operate
void Lifter::init() {
	liftEncoder.Reset();
	controller.Reset();
	controller.Enable();
}

//Operates lifter according to current state
void Lifter::update() {
	//std::cout << "bottom switch is: " << checkSensorHit(false) << std::endl;
	//std::cout << "top switch is: " << checkSensorHit(true) << std::endl;
	switch(state) {
	case MOVING:
		break;
	case IDLE:
		if(checkSensorHit(false)) {
			setLevel(0);
			liftEncoder.Reset();
		}
		break;
	}
}

//disables everything on lifter
void Lifter::disable() {
	victor.Disable();
	controller.Disable();
	state = IDLE;
}

//this method moves the lifter.
void Lifter::setLevel(double level) {
	controller.SetSetpoint(level * TOTE_HEIGHT);
	currentLevel = level;
	//Checks to see if the pid has reached its target.
	if(liftEncoder.GetStopped()) {
		state = IDLE;
	} else {
		state = MOVING;
	}
}
//this function moves the lifter to its lowest point to remove any error.
void Lifter::zeroing() {
	victor.Set(-.2);
//	state = ZEROING;
}

//void Lifter::setSpeed(double speed) {
//	victor.Set(speed);
//}

//Returns whether or not that sensor has been hit
//Param determines if first or second sensor is checked
bool Lifter::checkSensorHit(bool firstSensor) {
	if(firstSensor == false)
		return (digitalInput.Get());
	else
		return (digitalInput2.Get());
}

//Returns a boolean based on if either sensor has been hit
bool Lifter::checkEitherHit() {
	return (digitalInput.Get() || digitalInput2.Get());
}

//Gets the current state of the lifter.
Lifter::State Lifter::getState() {
	return state;
}

//Returns the current level of the lifter
double Lifter::getLevel() {
	return currentLevel;
}

//TODO Name of method is confusing, not what it actually does
//Moves the lifter at the specified speed
void Lifter::setSpeed(double speed) {
	state = MOVING;

	if(!checkSensorHit(false)) {
//		victor.SetSpeed((float) std::max(0.0, speed));
	} else if(!checkSensorHit(true)) {
//		victor.SetSpeed((float) std::min(0.0, speed));
	} else {
		victor.SetSpeed(speed);
	}
	victor.SetSpeed(speed);
}

//Empty destructor
Lifter::~Lifter() {
}
