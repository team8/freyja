/*
 * Version 7
 * 2/3/15
 * Jonathan Zwiebel
 */
#include "AutonomousExecutor.h"
#include <WPILib.h>
#include <stack>
#include "AutonomousController.h"
#include "Robot.h"
#include "Constants.h"

AutonomousExecutor::AutonomousExecutor(Robot *robotPointer, std::stack<AutonomousController::AutoCommand> *commandStack) {
	this->robot = robotPointer;
	this->commandStack = commandStack;
}

void AutonomousExecutor::executeCommand(AutonomousController::AutoCommand command) {
	switch(command) {
	case AutonomousController::CMD_STOP: {
		break;
	}
	case AutonomousController::CMD_FORWARD_DRIVE: {
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
	case AutonomousController::CMD_GRAY_FROM_GRAY: {
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
	case AutonomousController:CMD_CAN_LIFT: {
		canLift();
		break;
	}
	}
}

void AutonomousExecutor::toteScore() {
	commandStack->push(AutonomousController::CMD_DROP);
	commandStack->push(AutonomousController::CMD_FORWARD_DRIVE);
	commandStack->push(AutonomousController::CMD_LIFT);
}

void AutonomousExecutor::accumulateFromAuto() {

}

void AutonomousExecutor::toteToTote(bool isLeft) {

}

void AutonomousExecutor::canScore() {
	commandStack->push(AutonomousController::CMD_DROP);
	commandStack->push(AutonomousController::CMD_FORWARD_DRIVE);
	commandStack->push(AutonomousController::CMD_CAN_LIFT);
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

