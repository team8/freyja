#include "Robot.h"

/** Robot constructor, initializes robot and subsystems */
Robot::Robot() :
	//Initializes drivetrain, arm, and lifter
	drivetrain(), arm(), lifter() {
}

/** Initializes instance and subsystems */
void Robot::init() {
	//Calls initialization on subsystems
	drivetrain.init();
	arm.init();
	lifter.init();
}

/** Updates instance and subsystems */
void Robot::update() {
	//Calls update on subsystems
	drivetrain.update();
	arm.update();
	lifter.update();
}

/** Disables instance and subsystems */
void Robot::disable() {
	//Calls disable on subsystems
	drivetrain.disable();
	arm.disable();
	lifter.disable();
}

/** Wrapper method for drivetrain teleoperated movement */
void Robot::move(double targetSpeed, double rotateSpeed) {
	drivetrain.setSpeed(targetSpeed, rotateSpeed);
}

/** Wrapper method for changing piston state */
void Robot::changePistonState(Arm::PistonState state) {
	arm.setPistonState(state);
}

/** Wrapper method for changing the compressor state */
void Robot::changeCompressorState(Arm::CompressorState state) {
	arm.setCompressorState(state);
}

/** Wrapper method for driving a specified distance */
void Robot::driveDistance(double distance) {
	drivetrain.driveDistance(distance);
}

/** Wrapper method for rotating a specified angle */
void Robot::rotateAngle(double angle) {
	drivetrain.rotateAngle(angle);
}

/** Wrapper method for lifting a specified distance */
void Robot::lift(double distance) {
	//lifter.lift(distance);
}

/** Wrapper method for setting the lifter level */
void Robot::setLifterLevel(int level) {
	lifter.setLevel(level);
}

