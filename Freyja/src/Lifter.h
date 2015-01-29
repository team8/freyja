#ifndef SRC_LIFTER_H_
#define SRC_LIFTER_H_
#include "Subsys.h"
#include <WPILib.h>

class Lifter: public Subsys {
public:
	Lifter();
	virtual ~Lifter();
	void init();
	void update();
	void disable();
	void setSpeed(double speed);
	bool checkSensorHit();
	double getDistance(); //uses encoder
	void setLevel(int level);
	void moveToGroundLevel();

private:
	Talon motor;
	Encoder encoder;
	DigitalInput digitalInput;
	PIDController controller;

	int downSpeed = -0.5;
	int distanceToLevel = 0; //arbitrary number

};

#endif /* SRC_LIFTER_H_ */
