#include "Drivetrain.h"

Drivetrain::Drivetrain() :
		leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
//	leftMiddleTalon((uint32_t) 8),
		leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
		rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
//	rightMiddleTalon((uint32_t) 8),
		rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),

		leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
		rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false),

		gyro(PORT_GYRO),

		leftTopController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftTopTalon),
		leftBottomController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftBottomTalon),
		rightTopController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightTopTalon),
		rightBottomController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightBottomTalon)
{
	targetSpeed = 0;
	rotateSpeed = 0;

	leftEncoderVal = 0;
	rightEncoderVal = 0;
//Sets the distance per pulse, which is used for encoders
	leftEncoder.SetDistancePerPulse(LEFT_DPP);
	rightEncoder.SetDistancePerPulse(RIGHT_DPP);
//Sets the input range for pid controllers
	leftTopController.SetInputRange(-9999, 9999);
	rightTopController.SetInputRange(-9999, 9999);
	leftBottomController.SetInputRange(-9999, 9999);
	rightBottomController.SetInputRange(-9999, 9999);
//the state of the robot starts of idle
	state = IDLE;
}

void Drivetrain::init() {
	leftEncoder.Reset();
	rightEncoder.Reset();
}

void Drivetrain::disable() {
	stopTalons();
}

void Drivetrain::update() {
	switch(state)
	{
	case IDLE:
	{
		//Disable controllers

		stopTalons();

		break;
	}
	case DRIVING_DIST:
	{//'if' statement checks to see if the robot is at the destination
		if(std::abs(leftEncoderVal - leftEncoder.GetDistance()) < STOPPED_DRIVE_DIFF && std::abs(rightEncoderVal - rightEncoder.GetDistance()) < STOPPED_DRIVE_DIFF) {
			state = IDLE;        //sets state to idle if robot is at the destination
			leftTopController.Disable();
			rightTopController.Disable();
			leftBottomController.Disable();
			rightBottomController.Disable();
		}

		break;
	}
	case ROTATING_ANGLE:
	{
		//IF change condition : disable and set state to idle

		break;
	}
	case DRIVING_TELEOP:
	{
		//sets leftspeed and rightspeed

		double leftSpeed = std::max(std::min(targetSpeed - rotateSpeed, 1.0), -1.0);
		double rightSpeed = std::max(std::min(targetSpeed + rotateSpeed, 1.0), -1.0);
//sets the talons to leftspeed and rightspeed
		leftTopTalon.Set(leftSpeed);
		leftBottomTalon.Set(leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);

		break;
	}
	}

	leftEncoderVal = leftEncoder.GetDistance();
	rightEncoderVal = rightEncoder.GetDistance();
}

void Drivetrain::stopTalons() {
	leftTopTalon.Set(0.0);
	leftBottomTalon.Set(0.0);
	rightTopTalon.Set(0.0);
	rightBottomTalon.Set(0.0);
}

void Drivetrain::setSpeed(double targetSpeed, double rotateSpeed) {
	setTargetSpeed(targetSpeed);
	setRotateSpeed(rotateSpeed);
}

void Drivetrain::setTargetSpeed(double speed) {
	this->targetSpeed = speed;
}

void Drivetrain::setRotateSpeed(double speed) {
	this->rotateSpeed = speed;
}

void Drivetrain::rotateAngle(double angle) {
	state = ROTATING_ANGLE;

	//TODO Implement gyros and this method correctly
}

void Drivetrain::driveDistance(double distance) {
	state = DRIVING_DIST;
//resets the encoders before it drives
	leftEncoder.Reset();
	rightEncoder.Reset();
//drives the robot to a certain distance
	leftTopController.SetSetpoint(distance);
	leftBottomController.SetSetpoint(distance);
	rightTopController.SetSetpoint(distance);
	rightBottomController.SetSetpoint(distance);
//starts the controllers
	leftTopController.Enable();
	leftBottomController.Enable();
	rightTopController.Enable();
	rightBottomController.Enable();
}

Drivetrain::State Drivetrain::getState() {
	return state;
}

//Empty destructor
Drivetrain::~Drivetrain() {

}
