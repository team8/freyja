#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <WPILib.h>
#include <algorithm>
#include "Subsys.h"
#include "Constants.h"

class Drivetrain: public Subsys {
private:
//Victors are speed controllers. We initialize them here.
	Victor leftTopTalon;
	Victor leftBottomTalon;

	Victor rightTopTalon;
	Victor rightBottomTalon;

	double targetSpeed;
	double rotateSpeed;
//Encoder values are here. Encoders are things that measure the rotation of the wheels.
	double leftEncoderVal;
	double rightEncoderVal;
//We initialize the Encoders here.
	Encoder leftEncoder;
	Encoder rightEncoder;
//the gyro we use on the robot is here.
	Gyro gyro;
//PID controllers for the wheels. These essentially make sure the robot drives like it's supposed to.

	PIDController leftTopController;
	PIDController leftBottomController;

	PIDController rightTopController;
	PIDController rightBottomController;

public:
//making an enum called state that tells us what state the robot is in.
	typedef enum State
	{
		IDLE,
		DRIVING_DIST,
		ROTATING_ANGLE,
		DRIVING_TELEOP
	} State;

	State state;
//drivetrain constructor is here
	Drivetrain();
	virtual ~Drivetrain();
//various methods
	void init();

	void disable();

	void update();

	void stopTalons();

	void setSpeed(double targetSpeed, double rotateSpeed);

	void setTargetSpeed(double speed);
	void setRotateSpeed(double speed);

	void rotateAngle(double angle);

	void driveDistance(double distance);

	State getState();
};

#endif /* DRIVETRAIN_H */
