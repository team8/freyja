#include "Lifter.h"
#include <iostream>
Lifter::Lifter() :
		victor1((uint32_t) PORT_LIFT_VIC_1),
		victor2((uint32_t) PORT_LIFT_VIC_2),
		liftEncoder((uint32_t) LIFT_ENCODER_PORT_A, (uint32_t) LIFT_ENCODER_PORT_B, true),
		digitalInput((uint32_t) LIMIT_SWITCH_TOP),
		digitalInput2((uint32_t) LIMIT_SWITCH_BOT),

		controller1(0.3, 0.f, 0.1, &liftEncoder, &victor1),
		controller2(0.3, 0.f, 0.1, &liftEncoder, &victor2),

		speedController1(1.0, 0.f, 1.0, &liftEncoder, &victor1),
		speedController2(1.0, 0.f, 1.0, &liftEncoder, &victor2)
{
	currentLevel = 0;
	state = IDLE;
	height = 0;

	controller1.SetOutputRange(-0.5, 0.5);
	controller2.SetOutputRange(-0.5, 0.5);
}

//Initializes lifter to be ready to operate
void Lifter::init() {
	liftEncoder.Reset();
	controller1.Reset();
	controller2.Reset();

	liftEncoder.SetDistancePerPulse(LIFTER_DPP);
	controller1.SetInputRange(-9999, 9999);
	controller2.SetInputRange(-9999, 9999);
	liftEncoder.SetMaxPeriod(1);

//	liftEncoder.SetPIDSourceParameter(PIDSource::kRate);
}

//Operates lifter according to current state
void Lifter::update() {
//	std::cout << "digitalInput.Get(): " << digitalInput.Get() << std::endl << "digitalInput2.Get(): " << digitalInput2.Get() << std::endl;
//	std::cout << "Current lifter level: " << currentLevel << std::endl;
//	std::cout << "Lift Encoder: " << liftEncoder.PIDGet() << std::endl;
//	std::cout << "Lift Error: " << controller1.GetError() << std::endl;
	//std::cout << "Current Lifter state: " << state << std::endl;
	switch (state) {
	case MOVING:
		victor1.SetSpeed(- targetSpeed);
		victor2.SetSpeed(- targetSpeed);
		//std::cout << "Lift Encoder: " << liftEncoder.GetDistance() << std::endl;
		break;
	case AUTO_LIFTING:
		if (liftEncoder.GetStopped() && controller1.GetError() < 1) {
			state = IDLE;
		}
		break;
	case LEVEL_SHIFTING:
		if (liftEncoder.GetStopped() && controller1.GetError() < 1) {
			state = IDLE;
		}
		break;
	case IDLE:
		victor1.SetSpeed(0);
		victor2.SetSpeed(0);
		controller1.Disable();
		controller2.Disable();
		break;
	}
}

//disables everything on lifter
void Lifter::disable() {
	victor1.Disable();
	victor2.Disable();
	controller1.Disable();
	controller2.Disable();
	state = IDLE;
}

//this method moves the lifter.
void Lifter::setLevel(double level) {
	liftEncoder.SetPIDSourceParameter(PIDSource::kDistance);
	speedController1.Disable();
	speedController2.Disable();

	liftEncoder.Reset();
	controller1.SetSetpoint(level * TOTE_HEIGHT);
	controller2.SetSetpoint(level * TOTE_HEIGHT);
	currentLevel = level;
	height += level;
	state = LEVEL_SHIFTING;
}
//this function moves the lifter to its lowest point to remove any error.
void Lifter::zeroing() {
	liftEncoder.SetPIDSourceParameter(PIDSource::kDistance);
	speedController1.Disable();
	speedController2.Disable();

	liftEncoder.Reset();
	controller1.SetSetpoint(-height * TOTE_HEIGHT);
	controller2.SetSetpoint(-height * TOTE_HEIGHT);
	currentLevel = 0;
	height = 0;
	state = LEVEL_SHIFTING;
}

//void Lifter::setSpeed(double speed) {
//	victor.Set(speed);
//}

//Returns whether or not that sensor has been hit
//Param determines if first or second sensor is checked
bool Lifter::checkSensorHit(bool firstSensor) {
	if (firstSensor) {
		return (digitalInput.Get());
	} else {
		return (digitalInput2.Get());
	}
}

void Lifter::lift(double distance) {
	liftEncoder.SetPIDSourceParameter(PIDSource::kDistance);
	speedController1.Disable();
	speedController2.Disable();

	state = AUTO_LIFTING;

	//Enables pid controllers
	controller1.Enable();
	controller2.Enable();

	//Resets encoders
	liftEncoder.Reset();

	//Sets controller setpoint to given distance
	controller1.SetSetpoint(distance);
	controller2.SetSetpoint(distance);
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
	//std::cout << "Current lifter level: " << currentLevel << std::endl;
	return currentLevel;
}

//TODO Name of method is confusing, not what it actually does
//Moves the lifter at the specified speed
void Lifter::setSpeed(double speed) {
//	liftEncoder.SetPIDSourceParameter(PIDSource::kRate);
//
//	controller1.Disable();
//	controller2.Disable();
//
//	speedController1.SetSetpoint(speed);
//	speedController2.SetSetpoint(speed);
//
//	speedController1.Enable();
//	speedController2.Enable();

	state = MOVING;
	targetSpeed = speed;

//	//Check top limit switch, only move down
//	if (!checkSensorHit(true)) {
//		targetSpeed = std::min(0.0, speed);
//	}
//	//Check second limit switch, only move up
//	else if (!checkSensorHit(false)) {
//		targetSpeed = std::max(0.0, speed);
//	} else {
//		targetSpeed = speed;
//	}
//	state = MOVING;
}


//Empty destructor
Lifter::~Lifter() {
}
