/*
 * HumanController.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: EngTechP7
 */

#include <HumanController.h>
#include <WPIlib.h>

HumanController::HumanController(Robot *robotPointer) :
	moveJoystick( PORT_SPEED),
	turnJoystick( PORT_TURN)
	{

	}

void HumanController::update() {
	if (abs(moveJoystick.getY())<0.1){
		//set drivetrain forwardspeed to 0
	}
	else{
		//assign getX to drivetrain forwardspeed
	}
	if (abs(turnJoystick.getX())<0.1){
		//set drivetrain turnspeed to 0
	}
	else{
		//assign getY to drivetrain turnspeed
	}
}
