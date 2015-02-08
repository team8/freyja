#ifndef SRC_LIFTER_H_
#define SRC_LIFTER_H_
#include "Subsys.h"
#include <WPILib.h>
#include "Constants.h"

class Lifter: public Subsys {
public:
	Lifter();
	virtual ~Lifter();
	void init();
	void update();
	void disable();
	bool checkSensorHit();
	double getDistance(); //uses encoder
	void lift(double distance);
	void setLevel(double level);
	void zeroing();
	double getLevel();
	double currentLevel;

	typedef enum State{
		MOVING,
		IDLE,
		ZEROING
	}State;
	State state;

	State getState();

private:
	Talon motor;
	Encoder liftEncoder;
	DigitalInput digitalInput;
	PIDController controller;
};

#endif /* SRC_LIFTER_H_ */
