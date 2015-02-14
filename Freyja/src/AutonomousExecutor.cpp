/*
 * Version 9
 * 2/13/15
 * Jonathan Zwiebel
 */
#include "AutonomousExecutor.h"
#include <WPILib.h>
#include <list>
#include "AutonomousController.h"
#include "Robot.h"
#include "Constants.h"

AutonomousExecutor::AutonomousExecutor(Robot *robotPointer, std::list<AutonomousController::AutoCommand> *commandSet) {
	this->robot = robotPointer;
	this->commandSet = commandSet;
}

void AutonomousExecutor::executeCommand(AutonomousController::AutoCommand command) {
	switch(command) {
	case AutonomousController::CMD_STOP: {
		break;
	}
	case AutonomousController::CMD_AUTO_DRIVE: {
		drive(YELLOW_AUTO_DISTANCE);
		break;
	}
	case AutonomousController::CMD_LIFT: {
		lift();
		break;
	}
	case AutonomousController::CMD_DROP: {
		drop();
		break;
	}
	case AutonomousController::CMD_TOTE_SCORE: {
		toteScore();
		break;
	}
	case AutonomousController::CMD_ACCUMULATE_FROM_AUTO: {
		accumulateFromAuto();
		break;
	}
	case AutonomousController::CMD_TOTE_TO_TOTE_LEFT: {
		toteToTote(true);
		break;
	}
	case AutonomousController::CMD_TOTE_TO_TOTE_RIGHT: {
		toteToTote(false);
		break;
	}
	case AutonomousController::CMD_CAN_SCORE: {
		canScore();
		break;
	}
	case AutonomousController::CMD_DRIVE_LANDFILL_AUTO: {
		drive(AUTO_GRAY_DISTANCE);
		break;
	}
	case AutonomousController::CMD_GRAY_TO_GRAY: {
		grayToGray();
		break;
	}
	case AutonomousController::CMD_HALF_ROTATE: {
		rotate(180);
		break;
	}
	case AutonomousController::CMD_LANDFILL_DRIVE: {
		drive(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
		break;
	}
	case AutonomousController::CMD_CAN_LIFT: {
		canLift();
		break;
	}
	}
}

void AutonomousExecutor::toteScore() {
	commandSet->push_back(AutonomousController::CMD_DROP);
	commandSet->push_back(AutonomousController::CMD_AUTO_DRIVE);
	commandSet->push_back(AutonomousController::CMD_LIFT);
}

void AutonomousExecutor::accumulateFromAuto() {

}

void AutonomousExecutor::toteToTote(bool isLeft) {

}

void AutonomousExecutor::canScore() {
	commandSet->push_back(AutonomousController::CMD_DROP);
	commandSet->push_back(AutonomousController::CMD_AUTO_DRIVE);
	commandSet->push_back(AutonomousController::CMD_CAN_LIFT);
}

void AutonomousExecutor::grayToGray() {

}

void AutonomousExecutor::rotate(int angle) {
	robot->rotateAngle(180);
}

void AutonomousExecutor::canLift() {
	robot->canLift();
}

void AutonomousExecutor::drive(int dist) {
	robot->driveDistance(dist);
}

void AutonomousExecutor::lift() {
	robot->lift();
}

void AutonomousExecutor::drop() {
	robot->drop();
}

AutonomousExecutor::~AutonomousExecutor() {
	// TODO Auto-generated destructor stub
}

