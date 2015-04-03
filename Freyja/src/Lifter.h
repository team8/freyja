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
	void setState(double speed);
	void zeroing();
	void resetZero();
	double getLevel();
	double currentLevel;

	enum State {
		MOVING, AUTO_LIFTING, LEVEL_SHIFTING, IDLE
	} state;

	State getState();

	void setSpeed(double speed);

private:
	VictorSP victor1, victor2;
	Encoder liftEncoder;

	DigitalInput topLimitSwitch;
	DigitalInput botLimitSwitch;

	PIDController controller1, controller2;
//	PIDController speedController1, speedController2;

	double targetSpeed;
	int height;
	// how many totes high the lifter is currently at, by stroing this,
	// we can reset the encoders before every PID and this allows us to zero
};

#endif /* FREYJA_SRC_LIFTER_H_ */
