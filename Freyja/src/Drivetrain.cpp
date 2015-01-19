/*
 * Drivetrain.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: liam
 *      Author: Benjamin Cohen-Wang
 */

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
			rightBottomController(PROPORTIONAL, INTEGRAL, DERIVATIVE, &rightEncoder, &rightBottomTalon)
{
	targetSpeed = 0;
	rotateSpeed = 0;

	leftEncoder.SetDistancePerPulse(LEFT_DPP);
	rightEncoder.SetDistancePerPulse(RIGHT_DPP);
}

<<<<<<< HEAD
void Drivetrain::update(){
	leftSpeed = max(min(targetSpeed-rotateSpeed, 1.0), -1.0);
	rightSpeed = max(min(targetSpeed+rotateSpeed, 1.0), -1.0);

	leftTopTalon.Set(leftSpeed);
	//leftMiddleTalon.Set(leftSpeed);
	leftBottomTalon.Set(leftSpeed);
	rightTopTalon.Set(rightSpeed);
	//rightMiddleTalon.Set(rightSpeed);
	rightBottomTalon.Set(rightSpeed);
=======
Drivetrain::~Drivetrain() {
>>>>>>> 8b7a74b6d556837901b52490a1d7f075e1630b56

}

void Drivetrain::init() {

}

void Drivetrain::disable() {
	stopTalons();
}

void Drivetrain::update(){
	double leftSpeed = std::max(std::min(targetSpeed-rotateSpeed, 1.0), -1.0);
	double rightSpeed = std::max(std::min(targetSpeed+rotateSpeed, 1.0), -1.0);

	leftTopTalon.Set(leftSpeed);
	//leftMiddleTalon.Set(leftSpeed);
	leftBottomTalon.Set(leftSpeed);
	rightTopTalon.Set(rightSpeed);
	//rightMiddleTalon.Set(rightSpeed);
	rightBottomTalon.Set(rightSpeed);

}

void Drivetrain::stopTalons(){
	leftTopTalon.Set(0.0);
	//leftMiddleTalon.Set(0.0);
	leftBottomTalon.Set(0.0);
	rightTopTalon.Set(0.0);
	//rightMiddleTalon.Set(0.0);
	rightBottomTalon.Set(0.0);
}


void Drivetrain::setSpeed(double targetSpeed, double rotateSpeed){
	setTargetSpeed(targetSpeed);
	setRotateSpeed(rotateSpeed);
}

void Drivetrain::setTargetSpeed(double speed){
	this -> targetSpeed = speed;
}

void Drivetrain::setRotateSpeed(double speed){
	this -> rotateSpeed = speed;
}

void Drivetrain::rotateAngle(double angle){

}

void Drivetrain::driveDistance(double distance){

}
