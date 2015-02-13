#ifndef SRC_LIFTER_H_
#define SRC_LIFTER_H_
#include "Subsys.h"
#include <WPILib.h>
#include "Constants.h"

class Lifter: public Subsys {
public:
	Lifter();
	virtual ~Lifter();
	void init() override;
	void update() override;
	void disable() override;
	bool checkSensorHit();
	double getDistance(); //uses encoder
	void lift(double distance);
	void setLevel(double level);
	void zeroing();
	double getLevel();
	double currentLevel;

	enum State{
		MOVING,
		IDLE,
		ZEROING
	}state;

	State getState();

private:
	VictorSP motor;
	Encoder liftEncoder;
	DigitalInput digitalInput;
	PIDController controller;
};

#endif /* SRC_LIFTER_H_ */
