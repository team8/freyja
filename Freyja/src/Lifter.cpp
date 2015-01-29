#include "Lifter.h"

Lifter::Lifter() :
		motor((uint32_t) 0), encoder((uint32_t) 0, (uint32_t) 0), digitalInput((uint32_t) 0), controller(0.f, 0.f, 0.f, &encoder, &motor) {

}

Lifter::~Lifter() {
	// TODO Auto-generated destructor stub
}

void Lifter::init() {
	encoder.Reset();
	controller.Reset();
	controller.Enable();

}

void Lifter::update() {

	//this bit of code won't be used once we find distance between levels
//	if(ButtonPressed == 1 && checkSensorHit()) {
//		distanceToLevel = abs(getDistance());
//	}

//	if(downButton is Pressed){
//		moveToGroundLevel();
//	}

//have not set up joystick for lifter yet
//setLevel(HumanController Button Number);

	if(abs(getDistance() - distanceToLevel) > 1) {
		setSpeed(controller.Get());
	} else {
		setSpeed(0.0);
	}

}

void Lifter::disable() {
	motor.Disable();
	encoder.Reset();
	controller.Disable();

}

void Lifter::setLevel(int level) {
	distanceToLevel *= level;
	controller.SetSetpoint(distanceToLevel);
}

void Lifter::moveToGroundLevel() {
	setSpeed(downSpeed);
	init();
}

void Lifter::setSpeed(double speed) {
	motor.Set(speed);
}

bool Lifter::checkSensorHit() {
	if(digitalInput.Get() == 1) {
		return true;
	}
	return false;
}

double Lifter::getDistance() {
	return encoder.GetDistance();
}
