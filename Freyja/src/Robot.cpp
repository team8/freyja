#include "Robot.h"

Robot::Robot() :
	driveTrain(),
	arm()
{

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
	arm.disable();
}
void Robot::move(double Y, double X) {
	driveTrain.setSpeed(Y, X);

}

void Robot::changeArmState(Arm::State state){
	arm.setState(state);
}

