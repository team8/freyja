#include "Robot.h"

Robot::Robot() :
		drivetrain(), arm(), lifter() {

}

void Robot::init() {
	drivetrain.init();
	arm.init();
	lifter.init();
}

void Robot::update() {
	drivetrain.update();
	arm.update();
	lifter.update();
}

void Robot::disable() {
	drivetrain.disable();
	arm.disable();
}

void Robot::move(double targetSpeed, double rotateSpeed) {
	drivetrain.setSpeed(targetSpeed, rotateSpeed);
}

void Robot::changePistonState(Arm::PistonState state) {
	arm.setPistonState(state);
}
void Robot::changeCompressorState(Arm::CompressorState state) {
	arm.setCompressorState(state);
}

void Robot::driveDistance(double distance) {
	drivetrain.driveDistance(distance);
}

void Robot::rotateAngle(double angle) {
	drivetrain.rotateAngle(angle);
}

void Robot::lift() {
	//lifter.lift(distance);
}

void Robot::drop() {
}

void Robot::canLift() {
}

void Robot::setLifterLevel(int level) {
	lifter.setLevel(level);
}

Drivetrain::State Robot::getDrivetrainState() {
	return drivetrain.getState();
}

Lifter::State Robot::getLifterState() {
	return drivetrain.getState();
}

Arm::State Robot::getArmState() {
	return drivetrain.getState();
}

