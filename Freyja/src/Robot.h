#ifndef ROBOT_H
#define ROBOT_H

#include "Drivetrain.h"
#include "Arm.h"
#include "Lifter.h"

class Robot {
	private:
		Drivetrain drivetrain;
		Arm arm;
		Lifter lifter;

		enum state{
			TELEOP,
			AUTONOMOUS
		};
	public:
		Robot();
		void init();
		void update();
		void disable();
		void move(double y, double x);
		void changePistonState(Arm::PistonState state);
		void changeCompressorState(Arm::CompressorState state);
		void driveDistance(double distance);
		void rotateAngle(double angle);
		void lift(double distance);
		void setLifterLevel(int level);

		Drivetrain::State getDrivetrainState();
		Lifter::State getLifterState();
		Arm::State getArmState();
};

#endif /* ROBOT_H */
