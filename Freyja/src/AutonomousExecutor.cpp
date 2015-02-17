/*
 * Version 10
 * 2/14/15
 * Jonathan Zwiebel
 */

#include <WPILib.h>
#include "AutonomousExecutor.h"
#include <list>
#include "Robot.h"
#include "Constants.h"
#include <iterator>

AutonomousExecutor::AutonomousExecutor(Robot *robotPointer, std::list<AutoCommand> *commandSet) {
	this->robot = robotPointer;
	this->commandSet = commandSet;
}

void AutonomousExecutor::executeCommand(AutoCommand command) {
	std::cout << "AutonomousExecutor::executeCommand(" << command << ")" << std::endl;
	switch(command) {
	case CMD_STOP: {
		break;
	}
	case CMD_AUTO_DRIVE: {
		drive(YELLOW_AUTO_DISTANCE);
		break;
	}
	case ::CMD_LIFT: {
		lift();
		break;
	}
	case ::CMD_DROP: {
		drop();
		break;
	}
	case ::CMD_TOTE_SCORE: {
		toteScore();
		break;
	}
	case ::CMD_ACCUMULATE_FROM_AUTO: {
		accumulateFromAuto();
		break;
	}
	case ::CMD_TOTE_TO_TOTE_LEFT: {
		toteToTote(true);
		break;
	}
	case ::CMD_TOTE_TO_TOTE_RIGHT: {
		toteToTote(false);
		break;
	}
	case ::CMD_CAN_SCORE: {
		canScore();
		break;
	}
	case ::CMD_DRIVE_LANDFILL_AUTO: {
		drive(AUTO_GRAY_DISTANCE);
		break;
	}
	case ::CMD_GRAY_TO_GRAY: {
		grayToGray();
		break;
	}
	case ::CMD_HALF_ROTATE: {
		rotate(180);
		break;
	}
	case ::CMD_LANDFILL_DRIVE: {
		drive(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
		break;
	}
	case ::CMD_CAN_LIFT: {
		canLift();
		break;
	}
	}
}

void AutonomousExecutor::toteScore() {
	std::list<AutoCommand> toteScoreSet;
	toteScoreSet.push_back(CMD_LIFT);
	toteScoreSet.push_back(CMD_AUTO_DRIVE);
	toteScoreSet.push_back(CMD_DROP);

	comIt = commandSet->begin();
	advance(comIt, 1);
	commandSet->splice(comIt, toteScoreSet);
	commandSet->pop_front();
}

void AutonomousExecutor::accumulateFromAuto() {

}

void AutonomousExecutor::toteToTote(bool isLeft) {

}

void AutonomousExecutor::canScore() {
	std::list<AutoCommand> canScoreSet;
	canScoreSet.push_back(CMD_CAN_LIFT);
	canScoreSet.push_back(CMD_AUTO_DRIVE);
	canScoreSet.push_back(CMD_DROP);

	comIt = commandSet->begin();
	advance(comIt, 1);
	commandSet->splice(comIt, canScoreSet);
	commandSet->pop_front();
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
	robot->lift(10);
}

void AutonomousExecutor::drop() {
	robot->drop();
}

AutonomousExecutor::~AutonomousExecutor() {
	// TODO Auto-generated destructor stub
}

