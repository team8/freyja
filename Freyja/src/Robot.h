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
};

#endif /* ROBOT_H */
