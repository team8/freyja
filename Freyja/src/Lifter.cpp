#include "Lifter.h"

Lifter::Lifter() :
		motor((uint32_t) 0), liftEncoder((uint32_t) 0, (uint32_t) 0), digitalInput(
				(uint32_t) 0), controller(0.f, 0.f, 0.f, &liftEncoder, &motor) {
	state = IDLE;
}

Lifter::~Lifter() {

}

void Lifter::init() {
	liftEncoder.Reset();
	controller.Reset();
	controller.Enable();
}

void Lifter::update() {

	switch (state) {
	case MOVING:
	{
		break;
	}
	case IDLE:
	{
		liftEncoder.Reset();
		break;
	}
	case ZEROING:
	{
		if(checkSensorHit()) {
				setLevel(0);
				liftEncoder.Reset();
		}
		break;
	}
	}
}
//this bit of code won't be used once we find distance between levels
//	if(ButtonPressed == 1 && checkSensorHit()) {
//		distanceToLevel = abs(getDistance());
//	}

//	if(downButton is Pressed){
//		moveToGroundLevel();
//	}

//have not set up joystick for lifter yet
//setLevel(HumanController Button Number);

//	if(abs(getDistance() - distanceToLevel) > 1) {
//		setSpeed(controller.Get());
//	} else {
//		setSpeed(0.0);
//	}

//

void Lifter::disable() {
	motor.Disable();
	liftEncoder.Reset();
	controller.Disable();

}

//this method relies on not being called until after the PID is done
void Lifter::setLevel(double level) {
	controller.SetSetpoint(level);
	/*
	 * The following condition should be changed
	 *
	 * Consider a the belt zooming past the set point
	 */

	if (controller.GetError() < 0.5 && controller.GetError() > -0.5) {
		state = IDLE;
	}
	else {
		state = MOVING;
	}
}

	void Lifter::zeroing() {
		motor.Set(-.2);
		state = ZEROING;

	}

//void Lifter::setSpeed(double speed) {
//	motor.Set(speed);
//}

bool Lifter::checkSensorHit() {
	if (digitalInput.Get() == 1) {
		return true;
	}
	return false;
}

Lifter::State Lifter::getState() {
	return state;
}

double Lifter::getLevel() {

}
