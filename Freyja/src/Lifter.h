#ifndef FREYJA_SRC_LIFTER_H_
#define FREYJA_SRC_LIFTER_H_
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

	bool checkSensorHit(bool firstSensor);
	bool checkBottomHit();
	bool checkEitherHit();

	double getDistance();
	void lift(double distance);
	void setLevel(double level);
	void zeroing();
	double getLevel();
	double currentLevel;

	enum State {
		MOVING, IDLE
	} state;

	State getState();

	void setSpeed(double speed);

private:
	VictorSP victor;
	Encoder liftEncoder;

	DigitalInput digitalInput;
	DigitalInput digitalInput2;

	PIDController controller;
	double targetSpeed;
};

#endif /* FREYJA_SRC_LIFTER_H_ */
