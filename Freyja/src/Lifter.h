#ifndef SRC_LIFTER_H_
#define SRC_LIFTER_H_

#include <WPILib.h>
#include "Subsys.h"


class Lifter : public Subsys {
public:
	Lifter();
	virtual ~Lifter();
	void init();
	void update();
	void disable();
	void moveUp();
	void moveDown();
	bool checkSensorHit();
	double getDistance(); //uses encoder

	//unimplemented
	void runPIDLoop();

private:
	Talon motor1;
	Talon motor2;
	Encoder encoder;
	DigitalInput digitalInput;
	PIDController sensor;		//need to figure out constructor
};

#endif /* SRC_LIFTER_H_ */
