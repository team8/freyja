#include "Lifter.h"
#include <iostream>
Lifter::Lifter() :
		victor((uint32_t) PORT_LIFT_VIC), liftEncoder((uint32_t) LIFT_ENCODER_PORT_A,
				(uint32_t) LIFT_ENCODER_PORT_B),
				digitalInput((uint32_t) LIMIT_SWITCH_TOP),
				digitalInput2((uint32_t) LIMIT_SWITCH_BOT),
				controller(0.f, 0.f, 0.f,&liftEncoder, &victor), targetSpeed(0) {
	currentLevel = 0;
	state = IDLE;

}

//Initializes lifter to be ready to operate
void Lifter::init() {
	liftEncoder.Reset();
	controller.Reset();
	controller.Enable();
}

//Operates lifter according to current state
void Lifter::update() {
//	std::cout << "bottom switch is: " << checkSensorHit(false) << std::endl;
//	std::cout << "top switch is: " << checkSensorHit(true) << std::endl;
	//std::cout << "Lifter encoder" << liftEncoder.Get() << std::endl;
	switch (state) {
	case MOVING:
		std::cout << "Desired lifter speed: " << targetSpeed << std::endl;
		victor.SetSpeed(targetSpeed);
		std::cout << "Actual lifter speed: " << victor.Get() << std::endl;
		break;
	case IDLE:
		victor.SetSpeed(0);
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
	if (liftEncoder.GetStopped()) {
		std::cout << "Reached level " << level << std::endl;
		state = IDLE;
	} else {
		targetSpeed = controller.Get();
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
	//std::cout << "digInp: " << digitalInput.Get() << std::endl;
	//std::cout << "digInp2: " << digitalInput2.Get() << std::endl;
	if (firstSensor) {
		return (digitalInput.Get());
	} else {
		return (digitalInput2.Get());
	}
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
	// victor forward = downward
	//Check top limit switch, only move down
	if (checkSensorHit(true)) {
		std::cout << "Can't move up" << std::endl;
		targetSpeed = std::max(0.0, speed);
	}
	//Check second limit switch, only move up
	else if (checkSensorHit(false)) {
		std::cout << "Can't move down" << std::endl;
		targetSpeed = std::min(0.0, speed);
	} else {
		std::cout << "Limitless" << std::endl;
		targetSpeed = speed;
	}
	if (targetSpeed >= -0.1 && targetSpeed <= 0.1) {
		state = IDLE;
		std::cout << "lifter idling\n";
	}
	else {
		state = MOVING;
		std::cout << "lifter moving\n";
	}
}

//Empty destructor
Lifter::~Lifter() {
}
