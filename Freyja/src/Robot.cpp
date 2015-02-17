#include "Robot.h"

Robot::Robot() :
		drivetrain(), arm()/*lifter()*/ {

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

void Robot::changeDrivetrainStateToPRECISION_TRIGGER(){
	drivetrain.setStateTrigger();
}

void Robot::changeDrivetrainStateToBRAKE(){
	drivetrain.setStateBrake();
}

void Robot::lift(double distance) {
	//lifter.lift(distance);
}
void Robot::setLifterLevel(double level) {
	lifter.setLevel(level);
}

double Robot::getLevel() {
	lifter.getLevel();
}

void Robot::zeroLifter() {
	lifter.zeroing();
}


