#include "Robot.h"

Robot::Robot() :
	drivetrain(),
	arm()
{

}

void Robot::init() {
	drivetrain.init();
	arm.init();
}

void Robot::update() {
	drivetrain.update();
	arm.update();
}

void Robot::disable() {
	drivetrain.disable();
	arm.disable();
}

void Robot::move(double targetSpeed, double rotateSpeed) {
	drivetrain.setSpeed(targetSpeed, rotateSpeed);
}

void Robot::changeArmState(Arm::State state) {
	arm.setState(state);
}

void Robot::driveDistance(double distance) {
	drivetrain.driveDistance(distance);
}

void Robot::rotateAngle(double angle) {
	drivetrain.rotateAngle(angle);	
}

void Robot::lift(double distance) {
	//This method does not exist yet
	//lifter.lift(distance);
}
