/*
 * Joystick value -> encoder -> pid object -> talon
 *
 * PIDController
 */

#ifndef LIFTER_H
#define LIFTER_H

#include "Subsys.h"
#include <WPILib.h>


class Lifter : public Subsys {
public:
	Lifter();
	virtual ~Lifter();
	void init();
	void update();
	void disable();
	void setSpeed(double speed);
	bool checkSensorHit();
	double getDistance(); //uses encoder

private:
	Talon motor;
	Encoder encoder;
	DigitalInput digitalInput;
	PIDController controller;

	int upSpeed = 1;
	int downSpeed = 0;
	int distanceToTote = 2; //arbitrary number

};

#endif /* LIFTER_H */
