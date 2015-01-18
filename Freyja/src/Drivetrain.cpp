/*
 * Drivetrain.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: liam
 */

#include "Drivetrain.h"
#include <iostream>

Drivetrain::Drivetrain() :

			leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
			//leftMiddleTalon((uint32_t) 8),
			leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
			rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
			//rightMiddleTalon((uint32_t) 8),
			rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK)

{

	rotateSpeed = 0;
	targetSpeed = 0;
	leftSpeed = 0;
	rightSpeed = 0;

}

void Drivetrain::update(){
	leftSpeed = max(min(targetSpeed-rotateSpeed, 1.0), -1.0);
	rightSpeed = max(min(targetSpeed+rotateSpeed, 1.0), -1.0);

	leftTopTalon.Set(leftSpeed);
	//leftMiddleTalon.Set(leftSpeed);
	leftBottomTalon.Set(leftSpeed);
	rightTopTalon.Set(rightSpeed);
	//rightMiddleTalon.Set(rightSpeed);
	rightBottomTalon.Set(rightSpeed);

}

void Drivetrain::init() {

}

void Drivetrain::disable() {
	stopTalons();
}

void Drivetrain::stopTalons(){
	leftTopTalon.Set(0.0);
	//leftMiddleTalon.Set(0.0);
	leftBottomTalon.Set(0.0);
	rightTopTalon.Set(0.0);
	//rightMiddleTalon.Set(0.0);
	rightBottomTalon.Set(0.0);
}

Drivetrain::~Drivetrain() {
	// TODO Auto-generated destructor stub
}
void Drivetrain::move(double Y, double X){
	targetSpeed = Y;
	rotateSpeed = X;

}


