#include "Lifter.h"

Lifter::Lifter() :
victor((uint32_t) 9), liftEncoder((uint32_t) 0, (uint32_t) 0), digitalInput(
(uint32_t) 9), digitalInput2((uint32_t) 8), controller(0.f, 0.f, 0.f, &liftEncoder, &victor)
{
	state = IDLE;
	victor.Set(0);
}

Lifter::~Lifter() {

}
//starts everything that lifter contains
void Lifter::init() {
	liftEncoder.Reset();
	controller.Reset();
	controller.Enable();
	
	state = IDLE;
}
//updates lifter constantly
void Lifter::update() {

	//executes commands based on the state of the lifter
	switch (state) {
		case UP:
		{
			victor.Set(1.0);
			break;
		}
		case DOWN:
		{
			victor.Set(-1.0);
			break;
		}
		case IDLE:
		{
			victor.Set(0);
			break;
		}
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
	controller.SetSetpoint(level*TOTE_HEIGHT);
	/*
	 * Checks to see if the pid has reached its target.
	 * if it has, it reverts to idle state
	 * otherwise, it keeps moving.
	 */
	currentLevel = level;
	if (controller.GetError() < 0.5 && controller.GetError() > -0.5) {
		state = IDLE;
	}
}
//this function moves the lifter to its lowest point to remove any error.
void Lifter::zeroing() {
	victor.Set(-.2);

}

//void Lifter::setSpeed(double speed) {
//	victor.Set(speed);
//}

//returns a boolean based on if the sensor has been hit
bool Lifter::checkSensorHit(bool firstSensor) {
	if (firstSensor) return (digitalInput.Get() == 1);
	else return (digitalInput2.Get() == 1);
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

void Lifter::setState(double speed) {
	victor.Set(speed);
}
