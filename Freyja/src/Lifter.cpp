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
motor1((uint32_t) )
{

}

Lifter::~Lifter() {
	// TODO Auto-generated destructor stub
}

void Lifter::init() {
	motor1 = new Talon((uint32_t) 0);
	motor2 = new Talon((uint32_t) 0);
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
	motor1.Set(1.0);
}

void Lifter::moveDown() {
	motor1.Set(-1.0);
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
