#include <Robot.h>

Robot::Robot() :
	driveTrain()
{
	std::cout << "Robot constructor";
}

void Robot::init() {
	driveTrain.init();
}

void Robot::update() {
	driveTrain.update();
}

void Robot::disable() {
	driveTrain.disable();
}
