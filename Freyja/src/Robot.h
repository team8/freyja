/**
 * Represents the robot
 * Contains three subsystems, arm, drivetrain, and lifter
 * Initializes, disables, and updates these subsystems
 * Has wrapper methods that delegate tasks to subsystems
 */
#ifndef ROBOT_H
#define ROBOT_H

#include "Drivetrain.h"
#include "Arm.h"
#include "Lifter.h"

class Robot {
private:
	//The drivetrain, arm, and lifter subsystems
	Drivetrain drivetrain;
	Arm arm;
	Lifter lifter;

public:
	/** Robot constructor, initializes robot and subsystems */
	Robot();

	void init();
	void update();
	void disable();

	void move(double targetSpeed, double rotateSpeed);
	void driveDistance(double distance);
	void rotateAngle(double angle);
	void changeDrivetrainStateToPRECISION_TRIGGER();
	void changeDrivetrainStateToThrottle();
	void changeDrivetrainStateToHighSpeed();
	void changeDrivetrainStateToBrake();
	Drivetrain::State getDrivetrainState();
	Arm::PistonState getArmPistonState();

	void changePistonState(Arm::PistonState state);
	void changeCompressorState(Arm::CompressorState state);

	void drop();
	void liftCan();
	void setLifterLevel(int level);
	Lifter::State getLifterState();
	void zeroLifter();
	double getLevel();
	void setLifter(double speed);
	void liftDist(double dist);
};

#endif /* ROBOT_H */
