/*
 * HumanController.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#include <HumanController.h>

HumanController::HumanController() :
	moveJoystick( PORT_SPEED),
	turnJoystick( PORT_TURN)
	{

	}

void HumanController::update(Robot *robotPointer) {
	if (abs(moveJoystick.GetY())<0.1){
		//set drivetrain forwardspeed to 0
	}
	else{
		//assign getX to drivetrain forwardspeed
	}
	if (abs(turnJoystick.GetX())<0.1){
		//set drivetrain turnspeed to 0
	}
	else{
		//assign getY to drivetrain turnspeed
	}
	robotPointer -> move(moveJoystick.GetY(),turnJoystick.GetX());
}
