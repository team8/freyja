/* Brief and Probably Incorrect Description:
 *
 * -Victors power the motors to move the lift up or down
 * -the lifter will keep moving up until it hits a sensor, represented by a DigitalInput object
 * -each time it hits a sensor, it reaches a certain level of totes
 * -we have to measure how far up or down the lift is using an encoder
 * -using a PID Loop, minimize the error of the lift
 *
 */

#include "Lifter.h"

Lifter::Lifter():
motor1((uint32_t) 0),
motor2((uint32_t) 0),
encoder((uint32_t) 0, (uint32_t) 0),
digitalInput((uint32_t) 0)
//sensor(0.f, 0.f, 0.f, encoder, motor1)
{

}

Lifter::~Lifter() {
	// TODO Auto-generated destructor stub
}

void Lifter::init() {
	encoder.Reset();
}

void Lifter::update() {
	if(!checkSensorHit()) {
		moveUp();
	}

	else {
		//not sure
	}
}

void Lifter::disable() {
	motor1.Disable();
	motor2.Disable();

}

void Lifter::moveUp() {
	motor1.SetSpeed(1.0);
}

void Lifter::moveDown() {
	motor1.SetSpeed(-1.0);
}


bool Lifter::checkSensorHit() {
	return (digitalInput.Get() == 1);
}

double Lifter::getDistance() {
	return encoder.GetDistance();
}
