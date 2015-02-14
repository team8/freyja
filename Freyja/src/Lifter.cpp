#include "Lifter.h"

Lifter::Lifter() :
victor((uint32_t) 0), liftEncoder((uint32_t) 0, (uint32_t) 0), digitalInput(
(uint32_t) 0), controller(0.f, 0.f, 0.f, &liftEncoder, &victor) {
	state = IDLE;
}

Lifter::~Lifter() {

}
//starts everything that lifter contains
void Lifter::init() {
	liftEncoder.Reset();
	controller.Reset();
	controller.Enable();
}
//updates lifter constantly
void Lifter::update() {
	//executes commands based on the state of the lifter
	switch (state) {
		case MOVING:
		{
			break;
		}
		case IDLE:
		{
			disable();
			break;
		}
		case ZEROING:
			/** checks to see if a sensor at the bottom of the lifter has been hit
			 * if it has been hit, then reset the encoders
			 *the purpose of this is to get rid of any error for pid.
			 **/
		{
			if (checkSensorHit()) {
				setLevel(0);
				liftEncoder.Reset();
			}
			break;
		}
	}
}

//disables everything on lifter
void Lifter::disable() {
	victor.Set(0.0);
	victor.Disable();
	controller.Disable();
}

//this method moves the lifter.
void Lifter::setLevel(double level) {
	controller.SetSetpoint(level*TOTE_HEIGHT);
	/*
	 * Checks to see if the pid has reached its target.
	 * if it has, it reverts to idle state
	 * otherwise, it keeps moving.
	 */
	currentLevel = level;
	if (controller.GetError() < 0.5 && controller.GetError() > -0.5) {
		state = IDLE;
	} else {
		state = MOVING;
	}
}
//this function moves the lifter to its lowest point to remove any error.
void Lifter::zeroing() {
	victor.Set(-.2);
	state = ZEROING;

}

//void Lifter::setSpeed(double speed) {
//	victor.Set(speed);
//}

//returns a boolean based on if the sensor has been hit
bool Lifter::checkSensorHit() {
	if (digitalInput.Get() == 1) {
		return true;
	}
	return false;
}

//gets the current state of the lifter.
//this is used to tell other classes what state the lifter is in.
Lifter::State Lifter::getState() {
	return state;
}

//will return the current level of the lifter once it is complete.
double Lifter::getLevel() {
	return currentLevel;
}
