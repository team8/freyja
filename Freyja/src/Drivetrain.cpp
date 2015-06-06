#include "Drivetrain.h"

Drivetrain::Drivetrain() :
		//Initializes the left driving talons
		leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT), leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),

		//Initializes the right driving talons
		rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT), rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),

		//Initializes the two encoders with opposite orientations
		leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
		rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false),

		//Initializes the gyroscope
		gyro((int32_t) PORT_GYRO),

		//Initializes the PID controllers
		leftTopController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftTopTalon),
		leftBottomController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftBottomTalon),
		rightTopController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightTopTalon),
		rightBottomController(RIGHT_PROPORTIONAL, RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightBottomTalon),

		leftTopGyroController(GYRO_PROPORTIONAL, GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro, &leftTopTalon),
		leftBottomGyroController(GYRO_PROPORTIONAL, GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro, &leftBottomTalon),
		rightTopGyroController(GYRO_PROPORTIONAL,GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro, &rightTopTalon),
		rightBottomGyroController(GYRO_PROPORTIONAL, GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro, &rightBottomTalon)
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

	//Sets the output ranges for pid controllers
	leftTopController.SetOutputRange(-0.9, 0.9);
	rightTopController.SetOutputRange(-0.9, 0.9);
	leftBottomController.SetOutputRange(-0.9, 0.9);
	rightBottomController.SetOutputRange(-0.9, 0.9);

	leftTopGyroController.SetOutputRange(-0.7, 0.7);
	rightTopGyroController.SetOutputRange(-0.7, 0.7);
	leftBottomGyroController.SetOutputRange(-0.7, 0.7);
	rightBottomGyroController.SetOutputRange(-0.7, 0.7);

//Sets the max period for stopped detection
	leftEncoder.SetMaxPeriod(ENCODER_MAX_PERIOD);
	rightEncoder.SetMaxPeriod(ENCODER_MAX_PERIOD);

	//Sets the inital robot state to idle
	state = IDLE;
}

//Initializes the drivetrain
void Drivetrain::init() {
	//Sets the inital robot state to idle
	state = IDLE;

	//Resets encoders
	leftEncoder.Reset();
	rightEncoder.Reset();

	//Stops robot motion
	stopTalons();
}

//Disables the drivetrain
void Drivetrain::disable() {
	//Stops robot motion
	stopControl();
}

//Updates the drivetrain based on state machine
void Drivetrain::update() {
	std::cout << "State: " << state << std::endl;

	switch (state) {
	case IDLE:
		stopControl();
		break;
	case DRIVING_DIST:
		//Tests if the drivetrain has drived the specified distance and stops if it has
		if (leftEncoder.GetStopped() && rightEncoder.GetStopped() && std::abs(leftTopController.GetError()) < 1) {
			state = IDLE;
		}

		std::cout << "Left: " << leftEncoder.GetDistance() << std::endl;
		std::cout << "Right: " << rightEncoder.GetDistance() << std::endl;

		break;
	case ROTATING_ANGLE:
		//If angle is reached, stops rotating
		if (leftEncoder.GetStopped() && rightEncoder.GetStopped() && std::abs(leftTopGyroController.GetError()) < 1) {
			state = IDLE;
		}
		std::cout << "Gyro: " << gyro.GetAngle() << std::endl;

		break;
	case DRIVING_TELEOP:
	{
		//Determines the appropriate left and right speed
		double leftSpeed = std::max(std::min(targetSpeed * STANDARD_FORWARD_CONSTANT - rotateSpeed * ROTATE_CONSTANT, 1.0), -1.0);
		double rightSpeed = std::max(std::min(targetSpeed * STANDARD_FORWARD_CONSTANT + rotateSpeed * ROTATE_CONSTANT, 1.0), -1.0);

		double trueLeftSpeed = -std::pow(leftSpeed, 3);
		double trueRightSpeed = std::pow(rightSpeed, 3);

		double leftDiff = std::max(std::min(trueLeftSpeed - leftTopTalon.Get(), MAXIMUM_ACCELERATION), -MAXIMUM_ACCELERATION);
		double rightDiff = std::max(std::min(trueRightSpeed - rightTopTalon.Get(), MAXIMUM_ACCELERATION), -MAXIMUM_ACCELERATION);

		//Sets talons to left and right speeds
		leftTopTalon.Set(leftTopTalon.Get() + leftDiff);
		leftBottomTalon.Set(leftBottomTalon.Get() + leftDiff);
		rightTopTalon.Set(rightTopTalon.Get() + rightDiff);
		rightBottomTalon.Set(rightBottomTalon.Get() + rightDiff);

		break;
	}
	case PRECISION_TRIGGER:
	{
		//Determines the appropriate left and right speed
		double leftSpeed = std::max(std::min(targetSpeed - rotateSpeed * ROTATE_CONSTANT, 1.0), -1.0);
		double rightSpeed = std::max(std::min(targetSpeed + rotateSpeed * ROTATE_CONSTANT, 1.0), -1.0);

		//Sets talons to left and right speeds
		leftTopTalon.Set(-leftSpeed);
		leftBottomTalon.Set(-leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);
		break;
	}
	case HIGH_SPEED:
	{
		//Determines the appropriate left and right speed
		double leftSpeed = std::max(std::min(targetSpeed * HIGH_DPI - rotateSpeed * ROTATE_CONSTANT, 1.0), -1.0);
		double rightSpeed = std::max(std::min(targetSpeed * HIGH_DPI + rotateSpeed * ROTATE_CONSTANT, 1.0), -1.0);

		//Sets talons to left and right speeds
		leftTopTalon.Set(-leftSpeed);
		leftBottomTalon.Set(-leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);
		break;
	}
	case BRAKE:
		leftTopTalon.Set(leftTopTalon.Get() * 0.9);
		leftBottomTalon.Set(leftTopTalon.Get() * 0.9);
		rightTopTalon.Set(rightTopTalon.Get() * 0.9);
		rightBottomTalon.Set(rightTopTalon.Get() * 0.9);
		break;
	case SLOW_COAST:
		break;
	}
}

//Stops robot motion and control loops
void Drivetrain::stopControl() {
	//Stops all robot motion
	stopTalons();

	//Sets teleop speeds to idle
	setSpeed(0, 0);

	state = State::IDLE;

	//Disables pid controllers
	leftTopController.Disable();
	rightTopController.Disable();
	leftBottomController.Disable();
	rightBottomController.Disable();

	leftTopGyroController.Disable();
	rightTopGyroController.Disable();
	leftBottomGyroController.Disable();
	rightBottomGyroController.Disable();
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
	state = DRIVING_TELEOP;
	this->targetSpeed = speed;
}

//Sets drivetrain teleop rotate speed
void Drivetrain::setRotateSpeed(double speed) {
	state = DRIVING_TELEOP;
	this->rotateSpeed = speed;
}

//Rotates the given angle
void Drivetrain::rotateAngle(double angle) {
	stopControl();

	state = ROTATING_ANGLE;

	gyro.Reset();

	leftTopGyroController.SetSetpoint(angle);
	leftBottomGyroController.SetSetpoint(angle);
	rightTopGyroController.SetSetpoint(angle);
	rightBottomGyroController.SetSetpoint(angle);

	leftTopGyroController.Enable();
	leftBottomGyroController.Enable();
	rightTopGyroController.Enable();
	rightBottomGyroController.Enable();
}

//Drives the given distance
void Drivetrain::driveDistance(double distance) {
	stopControl();

	state = DRIVING_DIST;

	//Enables pid controllers
	leftTopController.Enable();
	leftBottomController.Enable();
	rightTopController.Enable();
	rightBottomController.Enable();

	//Resets encoders
	leftEncoder.Reset();
	rightEncoder.Reset();

	//Sets controller setpoint to given distance
	leftTopController.SetSetpoint(distance);
	leftBottomController.SetSetpoint(distance);
	rightTopController.SetSetpoint(distance);
	rightBottomController.SetSetpoint(distance);
}

//Turns on precision trigger
void Drivetrain::setStateTrigger() {
	state = PRECISION_TRIGGER;
}

//Start high dpi
void Drivetrain::setStateHighSpeed() {
	state = HIGH_SPEED;
}

void Drivetrain::setStateBrake() {
	state = BRAKE;
}

//Gets the state of this drivetrain
Drivetrain::State Drivetrain::getState() {
	return state;
}

//Empty destructor
Drivetrain::~Drivetrain() {

}
