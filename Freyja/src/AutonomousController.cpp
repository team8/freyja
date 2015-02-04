/*
 * Version 6
 * 1/29/15
 * Jonathan Zwiebel
 */

#include "AutonomousController.h"
using namespace std;


// FIX THESE NUMBERS
#define YELLOW_AUTO_DISTANCE 20
#define AUTO_GRAY_DISTANCE 20
#define GRAY_GRAY_DISTANCE 5
#define YELLOW_YELLOW_DISTANCE 15
#define LIFT_DISTANCE 5

AutonomousController::AutonomousController(Robot *robotPointer) :
	dial((uint32_t) PORT_AUTO_DIAL)
{
	cout << "AutonomousController constructed";
	this->robot = robotPointer;
	path = (Path) dial.GetValue();
	command = CMD_STOP;
}

void AutonomousController::init() {
	cout << path << " path called in AutonomousController::init";

	switch(path) {
		case STOP:
			stop();
			break;
		case DRIVE:
			drive();
			break;
		case TOTE_SCORE:
			toteScore();
			break;
		case TOTE_SCORE_ACCUMULATE:
			toteScoreAccumulate();
			break;
		case TOTE_SCORE_DOUBLE_LEFT:
			toteScoreDoubleLeft();
			break;
		case TOTE_SCORE_DOUBLE_RIGHT:
			toteScoreDoubleRight();
			break;
		case TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE:
			toteScoreDoubleLeftAccumulate();
			break;
		case TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE:
			toteScoreDoubleRightAccumulate();
			break;
		case TOTE_SCORE_TRIPLE:
			toteScoreTriple();
			break;
		case CAN_SCORE:
			canScore();
			break;
		case CAN_SCORE_ACCUMULATE:
			canScoreAccumulate();
			break;
		case ACCUMULATE:
			accumulate();
			break;
		case ACCUMULATE_DOUBLE:
			accumulateDouble();
			break;
		case ACCUMULATE_TRIPLE:
			accumulateTriple();
			break;
		}
}

void AutonomousController::update() {

}

void AutonomousController::callCommand(AutoCommand cmd) {
	cout << cmd << " command called in AutonomousController::callCommand";

	command = cmd;
	switch(command) {
	case CMD_STOP:
		stop();
		break;
	case CMD_DRIVE:
		drive();
		break;
	case CMD_TOTE_SCORE:
		toteScore();
		break;
	case CMD_TOTE_SCORE_ACCUMULATE:
		toteScoreAccumulate();
		break;
	case CMD_TOTE_SCORE_DOUBLE_LEFT:
		toteScoreDoubleLeft();
		break;
	case CMD_TOTE_SCORE_DOUBLE_RIGHT:
		toteScoreDoubleRight();
		break;
	case CMD_TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE:
		toteScoreDoubleLeftAccumulate();
		break;
	case CMD_TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE:
		toteScoreDoubleRightAccumulate();
		break;
	case CMD_TOTE_SCORE_TRIPLE:
		toteScoreTriple();
		break;
	case CMD_CAN_SCORE:
		canScore();
		break;
	case CMD_CAN_SCORE_ACCUMULATE:
		canScoreAccumulate();
		break;
	case CMD_ACCUMULATE:
		accumulate();
		break;
	case CMD_ACCUMULATE_DOUBLE:
		accumulateDouble();
		break;
	case CMD_ACCUMULATE_TRIPLE:
		accumulateTriple();
		break;
	case CMD_ACCUMULATE_FROM_SCORE:
		accumulateFromScore();
		break;
	case CMD_TOTE_TO_TOTE_RIGHT:
		toteToTote(true);
		break;
	case CMD_TOTE_TO_TOTE_LEFT:
		toteToTote(false);
		break;
	}
}

void AutonomousController::update() {

}

void AutonomousController::executeCommand(AutonomousCommand command) {
	(this -> currentCommand) = command;
}

void AutonomousController::stop() {
	path = STOP;
	command = CMD_STOP;
	cout << "AutonomousController::stop executed";
}

void AutonomousController::drive() {
	robot->driveDistance(YELLOW_AUTO_DISTANCE);
	callCommand(CMD_STOP);
}

void AutonomousController::toteScore() {
	robot->lift(LIFT_DISTANCE);
	robot->driveDistance(YELLOW_AUTO_DISTANCE);
	//robot->drop();
	callCommand(CMD_STOP);
}

void AutonomousController::toteScoreAccumulate() {
	callCommand(CMD_TOTE_SCORE);
	callCommand(CMD_ACCUMULATE_FROM_SCORE);
	callCommand(CMD_STOP);
}

void AutonomousController::toteScoreDoubleLeft() {
	robot->lift(LIFT_DISTANCE);
	callCommand(CMD_TOTE_TO_TOTE_LEFT);
	callCommand(CMD_TOTE_SCORE);
	callCommand(CMD_STOP);
}

void AutonomousController::toteScoreDoubleRight() {
	robot->lift(LIFT_DISTANCE);
	callCommand(CMD_TOTE_TO_TOTE_RIGHT);
	callCommand(CMD_TOTE_SCORE);
	callCommand(CMD_STOP);
}

void AutonomousController::toteScoreDoubleLeftAccumulate() {
	callCommand(CMD_TOTE_SCORE_DOUBLE_LEFT);
	callCommand(CMD_ACCUMULATE_FROM_SCORE);
	callCommand(CMD_STOP);
}

void AutonomousController::toteScoreDoubleRightAccumulate() {
	callCommand(CMD_TOTE_SCORE_DOUBLE_RIGHT);
	callCommand(CMD_ACCUMULATE_FROM_SCORE);
}

void AutonomousController::toteScoreTriple() {
	// magic
	callCommand(CMD_STOP);
}

void AutonomousController::canScore() {
	// robot->liftCan();
	robot->driveDistance(YELLOW_AUTO_DISTANCE);
	// robot->drop();
	callCommand(CMD_STOP);
}

void AutonomousController::canScoreAccumulate() {
	callCommand(CMD_CAN_SCORE);
	callCommand(CMD_ACCUMULATE_FROM_SCORE);
	callCommand(CMD_STOP);
}

void AutonomousController::accumulate() {
	robot->driveDistance(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(180);
	robot->driveDistance(AUTO_GRAY_DISTANCE);
	// robot->drop();
	callCommand(CMD_STOP);
}

void AutonomousController::accumulateDouble() {
	robot->driveDistance(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(90);
	robot->driveDistance(GRAY_GRAY_DISTANCE);
	robot->rotateAngle(-90);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(180);
	robot->driveDistance(AUTO_GRAY_DISTANCE);
		// robot->drop();
	callCommand(CMD_STOP);
}

void AutonomousController::accumulateTriple() {
	robot->driveDistance(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(90);
	robot->driveDistance(GRAY_GRAY_DISTANCE);
	robot->rotateAngle(-90);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(90);
	robot->driveDistance(GRAY_GRAY_DISTANCE);
	robot->rotateAngle(-90);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(180);
	robot->driveDistance(AUTO_GRAY_DISTANCE);
	// robot->drop();
	callCommand(CMD_STOP);
}

void AutonomousController::toteToTote(bool isRight) {
	if(isRight) {
		robot->rotateAngle(90);
		robot->driveDistance(YELLOW_YELLOW_DISTANCE);
		robot->rotateAngle(-90);
	}
	else {
		robot->rotateAngle(-90);
		robot->driveDistance(YELLOW_YELLOW_DISTANCE);
		robot->rotateAngle(90);
	}
	callCommand(CMD_STOP);
}

void AutonomousController::accumulateFromScore() {
	robot->driveDistance(-1);
	robot->rotateAngle(-90);
	robot->driveDistance(1);
	robot->rotateAngle(90);
	robot->driveDistance(1 + AUTO_GRAY_DISTANCE);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(180);
	robot->driveDistance(AUTO_GRAY_DISTANCE);
	callCommand(CMD_STOP);
}

//Empty destructor
AutonomousController::~AutonomousController() {}
