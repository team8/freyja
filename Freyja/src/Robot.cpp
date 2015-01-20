#include "Robot.h"

Robot::Robot() :
	driveTrain(),
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

void Robot::move(double Y, double X) {
	drivetrain.setSpeed(Y, X);

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
	lifter.lift(distance);	
}
}


}
