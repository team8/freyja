/*
 * Drivetrain.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: liam
 */

#include "Drivetrain.h"

Drivetrain::Drivetrain() :

			leftTopTalon((uint32_t) 8),
			leftMiddleTalon((uint32_t) 8),
			leftBottomTalon((uint32_t) 8),
			rightTopTalon((uint32_t) 8),
			rightMiddleTalon((uint32_t) 8),
			rightBottomTalon((uint32_t) 8)

{

	rotateSpeed = 0;
	targetSpeed = 0;
	leftSpeed = 0;
	rightSpeed = 0;

}

void Drivetrain::update(){
	leftSpeed = min(max(targetSpeed-rotateSpeed, -1), 1);
	rightSpeed = min(max(targetSpeed+rotateSpeed, 1), -1);

	leftTopTalon.Set(leftSpeed);
	leftMiddleTalon.Set(leftSpeed);
	leftBottomTalon.Set(leftSpeed);
	rightTopTalon.Set(rightSpeed);
	rightMiddleTalon.Set(rightSpeed);
	rightBottomTalon.Set(rightSpeed);

}

void Drivetrain::init() {
	
}

void Drivetrain::disable() {
	
}


//void Drivetrain::turnRight(){
//	leftTopTalon.Set(0.5);
//	leftMiddleTalon.Set(0.5);
//	leftBottomTalon.Set(0.5);
//	rightTopTalon.Set(0.25);
//	rightMiddleTalon.Set(0.25);
//	rightBottomTalon.Set(0.25);
//}
//
//void Drivetrain::turnLeft(){
//	leftTopTalon.Set(0.25);
//	leftMiddleTalon.Set(0.25);
//	leftBottomTalon.Set(0.25);
//	rightTopTalon.Set(0.5);
//	rightMiddleTalon.Set(0.5);
//	rightBottomTalon.Set(0.5);
//}
//
//void Drivetrain::moveForwardOrBackwards(double spd){
//	leftTopTalon.Set(spd);
//	leftMiddleTalon.Set(spd);
//	leftBottomTalon.Set(spd);
//	rightTopTalon.Set(spd);
//	rightMiddleTalon.Set(spd);
//	rightBottomTalon.Set(spd);
//}

void Drivetrain::stopTalons(){
	leftTopTalon.Set(0.0);
	leftMiddleTalon.Set(0.0);
	leftBottomTalon.Set(0.0);
	rightTopTalon.Set(0.0);
	rightMiddleTalon.Set(0.0);
	rightBottomTalon.Set(0.0);
}

Drivetrain::~Drivetrain() {
	// TODO Auto-generated destructor stub
}

