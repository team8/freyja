#include "Robot.h"
/** Robot constructor, initializes robot and subsystems */
Robot::Robot() :
		//Initializes drivetrain, arm, and lifter
		drivetrain(), arm(), lifter() {
}

/** Initializes subsystems */
void Robot::init() {
	drivetrain.init();
	arm.init();
	lifter.init();
}

/** Updates all subsystems */
void Robot::update() {
	drivetrain.update();
	arm.update();
	lifter.update();
	//disables lifter if either sensor is hit
	if(lifter.checkEitherHit()) {
		lifter.disable();
	}
}

/** Disables all subsystems */
void Robot::disable() {
	drivetrain.disable();
	arm.disable();
	lifter.disable();
}

/** Moves the robot according to an acceleration to move at, and
 * a rotateSpeed to turn by */
void Robot::move(double acceleration, double rotateSpeed) {
	drivetrain.setSpeed(acceleration, rotateSpeed);
}

/** Changes the piston state to a new PistonState */
void Robot::changePistonState(Arm::PistonState state) {
	arm.setPistonState(state);
}

/** Changes the compressor state to a new CompressorState */
void Robot::changeCompressorState(Arm::CompressorState state) {
	arm.setCompressorState(state);
}

/**  Drives the robot a specified distance */
void Robot::driveDistance(double distance) {
	drivetrain.driveDistance(distance);
}

/** Rotates the robot by a specific angle */
void Robot::rotateAngle(double angle) {
	drivetrain.rotateAngle(angle);
}

void Robot::changeDrivetrainStateToPRECISION_TRIGGER() {
	drivetrain.setStateTrigger();
}

void Robot::changeDrivetrainStateToBRAKE() {
	drivetrain.setStateBrake();
}

Drivetrain::State Robot::getDrivetrainState() {
	return drivetrain.getState();
}

Lifter::State Robot::getLifterState() {
	return lifter.getState();
}

/** Sets the lifter level */
void Robot::setLifterLevel(int level) {
	lifter.setLevel(level);
}
/** Returns the level of the lifter */
double Robot::getLevel() {
	return lifter.getLevel();
}

/** Zeroes the lifter */
void Robot::zeroLifter() {
	lifter.zeroing();
}

//TODO What are these two methods?
void Robot::drop() {
}

void Robot::canLift() {
}

void Robot::setLifter(double speed) {
	lifter.setState(speed);
}
