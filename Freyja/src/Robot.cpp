#include "Robot.h"

Robot::Robot() :
		drivetrain(), arm(), lifter() {

}

void Robot::init() {
	drivetrain.init();
	arm.init();
	//lifter.init();
}

void Robot::update() {
	drivetrain.update();
	arm.update();
	//lifter.update();
	
	//disables lifter if either sensor is hit
	if (lifter.checkSensorHit(true) || lifter.checkSensorHit(false))
		lifter.disable();
}

void Robot::disable() {
	drivetrain.disable();
	arm.disable();
}

void Robot::move(double acceleration, double rotateSpeed) {
	drivetrain.setSpeed(acceleration, rotateSpeed);
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

void Robot::changeDrivetrainStateToPRECISION_TRIGGER(){
	drivetrain.setStateTrigger();
}

void Robot::changeDrivetrainStateToBRAKE(){
	drivetrain.setStateBrake();
}

void Robot::lift(double distance) {

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
	return lifter.getState();
}

double Robot::getLevel() {
	lifter.getLevel();
}

void Robot::zeroLifter() {
	lifter.zeroing();
}

void Robot::setLifter(double speed) {
	lifter.setState(speed);
}
