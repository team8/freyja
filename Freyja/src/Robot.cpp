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
	arm.disable();
}
void Robot::move(double Y, double X) {
	driveTrain.move(Y, X);

}
void Robot::changeArmState(uint32_t button){
	if(button ARM_FORWARD_BUTTON){
		robot -> setArmState(Arm::EXTENDING);
	}
	if(button ARM_REVERSE_BUTTON)){
		robot -> setArmState(Arm::RETRACTING);
	}
	if(button ARM_FORWARD_BUTTON) && !(button ARM_REVERSE_BUTTON)
	{
		robot -> setArmState(Arm::IDLE);
	}
}

