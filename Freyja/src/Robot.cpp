#include "Robot.h"

Robot::Robot() :
	driveTrain()
	arm()
{
	std::cout << "Robot constructor";
}

void Robot::init() {
	driveTrain.init();
	arm.init();
}

void Robot::update() {
	driveTrain.update();
	arm.update();
}

void Robot::disable() {
	driveTrain.disable();
	arm();
}
void Robot::move(double Y, double X) {
	driveTrain.move(Y, X);

}
