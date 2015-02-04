#include "Drivetrain.h"

Drivetrain::Drivetrain() :
		//Initializes the left talons
		leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
		leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
		
		//Initializes the right talons
		rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
		rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),

		//Initializes the two encoders with opposite orientations
		leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
		rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false),

		//Initializes the gyroscope
		gyro(PORT_GYRO),

		//Initializes the pid controllers
		leftTopController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftTopTalon),
		leftBottomController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftBottomTalon),
		rightTopController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightTopTalon),
		rightBottomController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightBottomTalon)
{
	//Initializes the target and rotate speeds to zero
	targetSpeed = 0;
	rotateSpeed = 0;
	
	//Sets the encoder distance per pulses
	leftEncoder.SetDistancePerPulse(LEFT_DPP);
	rightEncoder.SetDistancePerPulse(RIGHT_DPP);
	
	//Sets the input ranges for pid controllers
	leftTopController.SetInputRange(-9999, 9999);
	rightTopController.SetInputRange(-9999, 9999);
	leftBottomController.SetInputRange(-9999, 9999);
	rightBottomController.SetInputRange(-9999, 9999);
	
	//Sets the max period for stopped detection
	leftEncoder.setMaxPeriod(ENCODER_MAX_PERIOD);
	rightEncoder.setMaxPeriod(ENCODER_MAX_PERIOD);
	
	//Sets the inital robot state to idle
	state = IDLE;
}

//Initializes the drivetrain
void Drivetrain::init() {
	//Resets encoders
	leftEncoder.Reset();
	rightEncoder.Reset();
	
	//Stops robot motion
	stopAllTalons();
}

//Disables the drivetrain
void Drivetrain::disable() {
	//Stops robot motion
	stopTalons();
}

//Updates the drivetrain
void Drivetrain::update() {
	//State machine for various states in update
	switch(state)
	{
	//Updates for the idle state
	case IDLE:
	{
		//Stops all robot motion
		stopTalons();

		//Disables pid controllers
		leftTopController.Disable();
		rightTopController.Disable();
		leftBottomController.Disable();
		rightBottomController.Disable();

		break;
	}
	//Updates for the driving distance state
	case DRIVING_DIST:
	{
		//Tests if the drivetrain has drived the specified distance
		if(leftEncoder.GetStopped() && rightEncoder.GetStopped()) {
			state = IDLE;
		}

		break;
	}
	//Updates for the rotating angle state
	case ROTATING_ANGLE:
	{
		//IF change condition : disable and set state to idle

		break;
	}
	//Updates for the teleop state
	case DRIVING_TELEOP:
	{
		//Determines the appropriate left and right speed
		double leftSpeed = std::max(std::min(targetSpeed - rotateSpeed, 1.0), -1.0);
		double rightSpeed = std::max(std::min(targetSpeed + rotateSpeed, 1.0), -1.0);
		
		//Sets talons to left and right speeds
		leftTopTalon.Set(leftSpeed);
		leftBottomTalon.Set(leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);

		break;
	}
	}
}

//Stops all drivetrain motion
void Drivetrain::stopTalons() {
	leftTopTalon.Set(0.0);
	leftBottomTalon.Set(0.0);
	rightTopTalon.Set(0.0);
	rightBottomTalon.Set(0.0);
}

//Sets drivetrain teleop target and rotate speed
void Drivetrain::setSpeed(double targetSpeed, double rotateSpeed) {
	setTargetSpeed(targetSpeed);
	setRotateSpeed(rotateSpeed);
}

//Sets drivetrain teleop target speed
void Drivetrain::setTargetSpeed(double speed) {
	this->targetSpeed = speed;
}

//Sets drivetrain teleop rotate speed
void Drivetrain::setRotateSpeed(double speed) {
	this->rotateSpeed = speed;
}

//Rotates the given angle
void Drivetrain::rotateAngle(double angle) {
	state = ROTATING_ANGLE;

	//TODO Implement gyros and this method correctly
}

//Drives the given distance
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

//Gets the state of this drivetrain
Drivetrain::State Drivetrain::getState() {
	return state;
}

//Empty destructor
Drivetrain::~Drivetrain() {

}
