/* Brief and Probably Incorrect Description:
 *
 * -Victors control the motors to move the lift up or down
 * -The lifter will keep moving up until it hits a sensor, represented by a DigitalInput object
 * -Each time it hits a sensor, it reaches a certain level of totes
 * -We have to measure how far up or down the lift is using an encoder
 * -Using a PID Loop, minimize the error of the lift
 */

#include "Lifter.h"

Lifter::Lifter():
motor((uint32_t) 0),
encoder((uint32_t) 0, (uint32_t) 0),
digitalInput((uint32_t) 0),
controller(0.f, 0.f, 0.f, &encoder, &motor)
{

}

void Lifter::init() {
	encoder.Reset();
	controller.Reset();
	controller.Enable();
}

void Lifter::update() {
	if(!checkSensorHit()) {
		//if(upButton is Pressed)
			setSpeed(upSpeed);
		//else
			//setSpeed(downSpeed);
	} else {
		setSpeed(0.0);
	}
}

void Lifter::disable() {
	motor.Disable();
	encoder.Reset();
	controller.Disable();
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

//Empty destructor
Lifter::~Lifter() {}
