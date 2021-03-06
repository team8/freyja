#include "Drivetrain.h"

Drivetrain::Drivetrain() :
		//Initializes the left talons
		leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT), leftBottomTalon(
				(uint32_t) PORT_DRIVE_VIC_LEFT_BACK),

		//Initializes the right talons
		rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT), rightBottomTalon(
				(uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),

		//Initializes the two encoders with opposite orientations
		leftEncoder((uint32_t) PORT_ENCODER_LEFT_A,
				(uint32_t) PORT_ENCODER_LEFT_B, true), rightEncoder(
				(uint32_t) PORT_ENCODER_RIGHT_A,
				(uint32_t) PORT_ENCODER_RIGHT_B, false),

		//Initializes the gyroscope
		gyro((int32_t) PORT_GYRO),

		//Initializes the pid controllers
		leftTopController(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE,
				&leftEncoder, &leftTopTalon), leftBottomController(
		LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder,
				&leftBottomTalon), rightTopController(RIGHT_PROPORTIONAL,
		RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder, &rightTopTalon), rightBottomController(
				RIGHT_PROPORTIONAL,
				RIGHT_INTEGRAL, RIGHT_DERIVATIVE, &rightEncoder,
				&rightBottomTalon),

//		leftTopTurn(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftTopTalon),
//		leftBottomTurn(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &leftEncoder, &leftBottomTalon),
//		rightTopTurn(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &rightEncoder, &rightTopTalon),
//		rightBottomTurn(LEFT_PROPORTIONAL, LEFT_INTEGRAL, LEFT_DERIVATIVE, &rightEncoder, &rightBottomTalon),

		leftTopGyroController(GYRO_PROPORTIONAL, GYRO_INTEGRAL, GYRO_DERIVATIVE,
				&gyro, &leftTopTalon), leftBottomGyroController(
		GYRO_PROPORTIONAL, GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro,
				&leftBottomTalon), rightTopGyroController(GYRO_PROPORTIONAL,
		GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro, &rightTopTalon), rightBottomGyroController(
		GYRO_PROPORTIONAL, GYRO_INTEGRAL, GYRO_DERIVATIVE, &gyro,
				&rightBottomTalon),

		//Initializes various instance variables
		leftSpeed(), rightSpeed(), drivingSetpoint() {
	//Initializes the target and rotate speeds to zero
	targetSpeed = 0;
	rotateSpeed = 0;
	rawTargetSpeed = 0;
	rawTurnInput = 0;
	rawDriveInput = 0;
	acceleration = 0;


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

//	leftTopTurn.SetInputRange(-9999, 9999);
//	leftBottomTurn.SetInputRange(-9999, 9999);
//	rightTopTurn.SetInputRange(-9999, 9999);
//	rightBottomTurn.SetInputRange(-9999, 9999);

//	leftTopTurn.SetOutputRange(-0.7, 0.7);
//	rightTopTurn.SetOutputRange(-0.7, 0.7);
//	leftBottomTurn.SetOutputRange(-0.7, 0.7);
//	rightBottomTurn.SetOutputRange(-0.7, 0.7);

//Sets the max period for stopped detection
	leftEncoder.SetMaxPeriod(ENCODER_MAX_PERIOD);
	rightEncoder.SetMaxPeriod(ENCODER_MAX_PERIOD);

	//Sets the inital robot state to idle
	state = IDLE;
}

//Initializes the drivetrain
void Drivetrain::init() {

	leftSpeed = 0;
	rightSpeed = 0;

	//Sets the inital robot state to idle
	state = IDLE;
//	gyro.InitGyro();
	//Resets encoders
	leftEncoder.Reset();
	rightEncoder.Reset();

	//Stops robot motion
	stopTalons();
	//driveDistance(100);
	//rotateAngle(90);
}

//Disables the drivetrain
void Drivetrain::disable() {
	//Stops robot motion
	stopControl();
}

void Drivetrain::setRaws(double driveSpeed, double turnSpeed) {
	this->rawDriveInput = driveSpeed;
	this->rawTargetSpeed = turnSpeed;
}

//Updates the drivetrain based on state machine
void Drivetrain::update() {
	//std::cout << "State: " << state << std::endl;

	switch (state) {
	case IDLE:
		stopControl();
		break;
	case DRIVING_DIST:
		//Tests if the drivetrain has drived the specified distance and stops if it has
		if (leftEncoder.GetStopped() && rightEncoder.GetStopped()
				&& std::abs(leftTopController.GetError()) < 1) {
			state = IDLE;
		}

		std::cout << "Left: " << leftEncoder.GetDistance() << std::endl;
		std::cout << "Right: " << rightEncoder.GetDistance() << std::endl;

		break;
	case ROTATING_ANGLE:
		//If angle is reached, stops rotating
		if (leftEncoder.GetStopped() && rightEncoder.GetStopped()
				&& std::abs(leftTopGyroController.GetError()) < 1) {
			state = IDLE;
		}
		std::cout << "Gyro: " << gyro.GetAngle() << std::endl;
		break;
	case DRIVING_TELEOP:
/*		leftSpeed = std::max(std::min(rawDriveInput - rawTurnInput, 0.75), -0.75);
		rightSpeed = std::max(std::min(rawDriveInput + rawTurnInput, 0.75), -0.75);
		std::cout << "RDI: " << rawDriveInput << std::endl;
		std::cout << "RTI: " << rawTurnInput << std::endl;
		std::cout << "LS: " << leftSpeed << std::endl;
		std::cout << "RS: " << rightSpeed << std::endl;*/
		//Determines the appropriate left and right speed
		leftSpeed =std::max(std::min(targetSpeed *.9 - rotateSpeed * ROTATE_CONSTANT, 0.95),-0.95);
		rightSpeed =std::max(std::min(targetSpeed * .9 + rotateSpeed * ROTATE_CONSTANT, 0.95),-0.95);

//		leftSpeed = std::max(
//				std::min(targetSpeed - rotateSpeed * ROTATE_CONSTANT, 0.75),-0.75);
//		rightSpeed = std::max(
//				std::min(targetSpeed + rotateSpeed * ROTATE_CONSTANT, 0.75),-0.75);
		//Determines the appropriate left and right speed

		//Sets talons to left and right speeds
		leftTopTalon.Set(-leftSpeed);
		leftBottomTalon.Set(-leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);
//		std::cout << "Left Encoder: " << leftEncoder.GetDistance() << std::endl;
//		std::cout << "Right Encoder: " << rightEncoder.GetDistance() << std::endl;
//		std::cout << "Gyro: " << gyro.GetAngle() << std::endl;
//		std::cout << "Left Top Actual Speed: " << leftTopTalon.Get() << std::endl;
//		std::cout << "Left Desired Speed: " << -leftSpeed << std::endl;
//		std::cout << "Right Top Actual Speed: " << rightTopTalon.Get() << std::endl;
//		std::cout << "Right Desired Speed: " << rightSpeed << std::endl;
//		std::cout << "Left Encoder Raw: " << leftEncoder.GetRaw() << std::endl;
//		std::cout << "Right Encoder Raw: " << rightEncoder.GetRaw() << std::endl;
//		std::cout << "Left Talon Top Out: " << leftTopTalon.Get() << std::endl;
//		std::cout << "Left Talon Bottom Out: " << leftBottomTalon.Get() << std::endl;
//		std::cout << "right Talon Top Out: " << rightTopTalon.Get() << std::endl;
//		std::cout << "right Talon Bottom Out: " << rightBottomTalon.Get() << std::endl;
//		std::cout << "Left Raw: " << leftEncoder.GetRaw() << std::endl;
//		std::cout << "Right Raw: " << rightEncoder.GetRaw() << std::endl;
//		std::cout << "Left Direction: " << leftEncoder.GetDirection() << std::endl;
//		std::cout << "Right Direction: " << rightEncoder.GetDirection() << std::endl;
//		std::cout << "Left Bot Speed: " << leftBottomTalon.Get() << std::endl;
//		std::cout << "Right Top Speed: " << rightTopTalon.Get() << std::endl;
//		std::cout << "Right Bot Speed: " << rightBottomTalon.Get() << std::endl;
//		std::cout << "Target Speed: " << targetSpeed << std::endl;
//		std::cout << "Acceleration: " << acceleration << std::endl;

		break;

	case PRECISION_TRIGGER:
		//Determines the appropriate left and right speed
		leftSpeed =std::max(std::min(targetSpeed * LOW_DPI- rotateSpeed * ROTATE_CONSTANT, 0.95),-0.95);
		rightSpeed =std::max(std::min(targetSpeed * LOW_DPI+ rotateSpeed * ROTATE_CONSTANT, 0.95),-0.95);

		//Sets talons to left and right speeds
		leftTopTalon.Set(-leftSpeed);
		leftBottomTalon.Set(-leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);
		break;

	case THROTTLE:
		//Stops Talons
		//stopTalons();
		acceleration = 0;
		targetSpeed = 1;
		//Goes backwards
		leftTopTalon.Set(-1);
		leftBottomTalon.Set(-1);
		rightTopTalon.Set(1);
		rightBottomTalon.Set(1);
		break;

	case HIGH_SPEED:
		//Determines the appropriate left and right speed
		leftSpeed = std::max(
				std::min(targetSpeed * HIGH_DPI - rotateSpeed * ROTATE_CONSTANT,1.0), -1.0);
		rightSpeed = std::max(
				std::min(targetSpeed * HIGH_DPI + rotateSpeed * ROTATE_CONSTANT,1.0), -1.0);

		//Sets talons to left and right speeds
		leftTopTalon.Set(-leftSpeed);
		leftBottomTalon.Set(-leftSpeed);
		rightTopTalon.Set(rightSpeed);
		rightBottomTalon.Set(rightSpeed);
		break;

	case BRAKE:
		std::cout << "in break state" << std::endl;
		leftTopTalon.Set(leftTopTalon.Get() * 0.9);
		leftBottomTalon.Set(leftTopTalon.Get() * 0.9);
		rightTopTalon.Set(rightTopTalon.Get() * 0.9);
		rightBottomTalon.Set(rightTopTalon.Get() * 0.9);
		break;
	case SLOW_COAST:
//		int coastSpeedConstant;
//		int coastTurnConstant;

//		/*if (targetSpeed < 0 && rotateSpeed < 0) {
//			leftSpeed = std::max(std::min(0.1 + 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//			rightSpeed = std::max(std::min(0.1 - 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//					//Determines the appropriate left and right speed
//
//					//Sets talons to left and right speeds
//					leftTopTalon.Set(-leftSpeed);
//					leftBottomTalon.Set(-leftSpeed);
//					rightTopTalon.Set(rightSpeed);
//					rightBottomTalon.Set(rightSpeed);
//
//		} else if (targetSpeed > 0 && rotateSpeed < 0) {
//			leftSpeed = std::max(std::min(0.1 + 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//			rightSpeed = std::max(std::min(0.1 - 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//					//Determines the appropriate left and right speed
//
//					//Sets talons to left and right speeds
//					leftTopTalon.Set(leftSpeed);
//					leftBottomTalon.Set(leftSpeed);
//					rightTopTalon.Set(-rightSpeed);
//					rightBottomTalon.Set(-rightSpeed);
//
//		} else if (targetSpeed < 0 && rotateSpeed > 0) {
//			leftSpeed = std::max(std::min(0.1 - 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//			rightSpeed = std::max(std::min(0.1 + 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//					//Determines the appropriate left and right speed
//
//					//Sets talons to left and right speeds
//					leftTopTalon.Set(-leftSpeed);
//					leftBottomTalon.Set(-leftSpeed);
//					rightTopTalon.Set(rightSpeed);
//					rightBottomTalon.Set(rightSpeed);
//
//		} else if (targetSpeed > 0 && rotateSpeed > 0) {
//			leftSpeed = std::max(std::min(0.1 - 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//			rightSpeed = std::max(std::min(0.1 + 0.05 * ROTATE_CONSTANT, 0.75),-0.75);
//					//Determines the appropriate left and right speed
//
//					//Sets talons to left and right speeds
//					leftTopTalon.Set(leftSpeed);
//					leftBottomTalon.Set(leftSpeed);
//					rightTopTalon.Set(-rightSpeed);
//					rightBottomTalon.Set(-rightSpeed);
//
//		} else if (targetSpeed > 0 && rotateSpeed == 0) {
//
//		}*/
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
void Drivetrain::setSpeed(double myAcceleration, double rotateSpeed) {
	acceleration = myAcceleration;
	//this->rotateSpeed = rotateSpeed;
	if (acceleration > -SPEED_DECAY_RANGE && acceleration < SPEED_DECAY_RANGE) {
		setTargetSpeed(targetSpeed * SPEED_DECAY_CONSTANT);
	}
	// multipling to check sign
	if (acceleration * targetSpeed < 0) {
		setTargetSpeed(
				targetSpeed + acceleration * ACCELERATION_REVERSE_CONSTANT);
	} else {
		setTargetSpeed(targetSpeed + acceleration * ACCELERATION_CONSTANT);
	}
	setRotateSpeed(rotateSpeed);

	//Sets the raw target speed to joystick displacement, don't be confused by myAcceleration setting
	this->rawTargetSpeed = myAcceleration;
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
	std::cout << "INVALID GRYO STATE CHANGE" << std::endl;


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

	//Resets encoders
//	leftEncoder.Reset();
//	rightEncoder.Reset();

//	leftTopTurn.SetSetpoint(angle*DISTANCE_PER_DEGREE);
//	leftBottomTurn.SetSetpoint(angle*DISTANCE_PER_DEGREE);
//	rightTopTurn.SetSetpoint(angle*DISTANCE_PER_DEGREE);
//	rightBottomTurn.SetSetpoint(angle*DISTANCE_PER_DEGREE);

//	leftTopTurn.Enable();
//	leftBottomTurn.Enable();
//	rightTopTurn.Enable();
//	rightBottomTurn.Enable();

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
//Turns on the throttle
void Drivetrain::setStateThrottle() {
	state = THROTTLE;
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
