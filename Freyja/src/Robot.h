#ifndef ROBOT_H
#define ROBOT_H

#include "Drivetrain.h"
#include "Arm.h"
#include "Lifter.h"

/**
 * Represents the physical robot
 * Contains three subsystems, arm, drivetrain, and lifter
 * Runs these subsystems by initializing, updating, and disabling them as needed
 * Has wrapper methods and commands that delegate tasks to subsystems
 */
class Robot {
	private:
		Drivetrain drivetrain;
		Arm arm;
		Lifter lifter;

	public:
		Robot();
		void init();
		void update();
		void disable();

		//Drivetrain commands
		void move(double targetSpeed, double rotateSpeed);
		void driveDistance(double distance);
		void rotateAngle(double angle);

		//Arm commands
		void changePistonState(Arm::PistonState state);
		void changeCompressorState(Arm::CompressorState state);

		//Lifter commands
		void lift(double distance);
		void setLifterLevel(double level);
		void zeroLifter();
		double getLevel();
};

#endif /* ROBOT_H */
