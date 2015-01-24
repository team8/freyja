/*
 * Joystick value -> encoder -> pid object -> talon
 *
 * PIDController
 *
 */

#ifndef SRC_LIFTER_H_
#define SRC_LIFTER_H_
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
<<<<<<< HEAD
	void lift(double distance);
=======
>>>>>>> 00bbeea0188fb6808ca6dc3bf647da7b43af9be0

private:
	Talon motor;
	Encoder encoder;
	DigitalInput digitalInput;
	PIDController controller;

	int upSpeed = 1;
	int downSpeed = 0;
	int distanceToTote = 2; //arbitrary number

};

#endif /* SRC_LIFTER_H_ */
