#include "Drivetrain.h"
#include "Constants.h"

Drivetrain::Drivetrain() :

			leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
			//leftMiddleTalon((uint32_t) 8),
			leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
			rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
			//rightMiddleTalon((uint32_t) 8),
			rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK),

			leftEncoder((uint32_t) PORT_ENCODER_LEFT_A, (uint32_t) PORT_ENCODER_LEFT_B, true),
			rightEncoder((uint32_t) PORT_ENCODER_RIGHT_A, (uint32_t) PORT_ENCODER_RIGHT_B, false),

			gyro(PORT_GYRO),

			leftTopController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &leftEncoder, &leftTopTalon),
			leftBottomController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &leftEncoder, &leftBottomTalon),
			rightTopController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &rightEncoder, &rightTopTalon),
			rightBottomController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &rightEncoder, &rightBottomTalon),
			
			leftTopGyroController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &leftEncoder, &leftTopTalon),
			leftBottomGyroController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &leftEncoder, &leftBottomTalon),
			rightTopGyroController(-PROPORTIONAL, -INTEGRAL, -DERIVATIVE, &rightEncoder, &rightTopTalon),
			rightBottomGyroController(-PROPORTIONAL, -INTEGRAL, -DERIVATIVE, &rightEncoder, &rightBottomTalon)
{
	targetSpeed = 0;
	rotateSpeed = 0;

	leftEncoder.SetDistancePerPulse(LEFT_DPP);
	rightEncoder.SetDistancePerPulse(RIGHT_DPP);
	leftTopController.SetInputRange(-1, 1);
	rightTopController.SetInputRange(-1,1);
	leftBottomController.SetInputRange(-1,1);
	rightBottomController.SetInputRange(-1,1);
}

void Drivetrain::init() {
	leftEncoder.Reset();
	rightEncoder.Reset();
}

void Drivetrain::disable() {
	stopTalons();
}

void Drivetrain::update() {
	double leftSpeed = std::max(std::min(targetSpeed-rotateSpeed, 1.0), -1.0);
	double rightSpeed = std::max(std::min(targetSpeed+rotateSpeed, 1.0), -1.0);

	std::cout<<"update dt" <<std::endl;
	leftTopTalon.Set(leftSpeed);
	leftBottomTalon.Set(leftSpeed);
	rightTopTalon.Set(rightSpeed);
	rightBottomTalon.Set(rightSpeed);
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
	this -> targetSpeed = speed;
}

void Drivetrain::setRotateSpeed(double speed) {
	this -> rotateSpeed = speed;
}

void Drivetrain::rotateAngle(double angle) {
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

void Drivetrain::driveDistance(double distance) {
	leftEncoder.Reset();
	rightEncoder.Reset();

	leftTopController.SetSetpoint(distance);
	leftBottomController.SetSetpoint(distance);
	rightTopController.SetSetpoint(distance);
	rightBottomController.SetSetpoint(distance);

	leftTopController.Enable();
	leftBottomController.Enable();
	rightTopController.Enable();
	rightBottomController.Enable();
}

//Empty destructor
Drivetrain::~Drivetrain() {}
