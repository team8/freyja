/*
 * Drivetrain.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: liam
 */

#include "Drivetrain.h"

Drivetrain::Drivetrain() :

			leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
			//leftMiddleTalon((uint32_t) 8),
			leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
			rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
			//rightMiddleTalon((uint32_t) 8),
			rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK)

{
	targetSpeed = 0;
	rotateSpeed = 0;
}

Drivetrain::~Drivetrain() {

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


void Drivetrain::move(double targetSpeed, double rotateSpeed){
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
