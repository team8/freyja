/*
 * Version 5
 * 1/20/15 at 2100
 * Jonathan Zwiebel
 */

#include "AutonomousController.h"

#define PATH 0
#define YELLOW_AUTO_DISTANCE 20
#define AUTO_GRAY_DISTANCE 20
#define GRAY_GRAY_DISTANCE 5
#define YELLOW_YELLOW_DISTANCE 15
#define LIFT_DISTANCE 5

enum path {
	STOP = 0,
	DRIVE = 1,
	TOTE_SCORE = 2,
	TOTE_SCORE_ACCUMULATE = 3,
	TOTE_SCORE_DOUBLE_LEFT = 4,
	TOTE_SCORE_DOUBLE_RIGHT = 5,
	TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE = 6,
	TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE = 7,
	TOTE_SCORE_TRIPLE = 8,
	CAN_SCORE = 9,
	CAN_SCORE_ACCUMULATE = 10,
	ACCUMULATE = 11,
	ACCUMULATE_DOUBLE = 12,
	ACCUMULATE_TRIPLE = 13
};



AutonomousController::AutonomousController(Robot *robotPointer) :
	dial((uint32_t) PORT_AUTO_DIAL)
{
	this->robot = robotPointer;
	std::cout << "AutonomousController constructed" << std::endl;

	path = dial.GetValue();

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

void AutonomousController::stop() {

}

void AutonomousController::drive() {
	robot->driveDistance(YELLOW_AUTO_DISTANCE);
}

void AutonomousController::toteScore() {
	robot->lift(LIFT_DISTANCE);
	robot->driveDistance(YELLOW_AUTO_DISTANCE);
	//robot->drop();
}

void AutonomousController::toteScoreAccumulate() {
	toteScore();
	accumulateFromScore();
}

void AutonomousController::toteScoreDoubleLeft() {
	robot->lift(LIFT_DISTANCE);
	toteToTote(false);
	toteScore();
}

void AutonomousController::toteScoreDoubleRight() {
	robot->lift(LIFT_DISTANCE);
	toteToTote(true);
	toteScore();
}

void AutonomousController::toteScoreDoubleLeftAccumulate() {
	toteScoreDoubleLeft();
	accumulateFromScore();
}

void AutonomousController::toteScoreDoubleRightAccumulate() {
	toteScoreDoubleRight();
	accumulateFromScore();
}

void AutonomousController::toteScoreTriple() {
	// magic
}

void AutonomousController::canScore() {
	// robot->liftCan();
	robot->driveDistance(YELLOW_AUTO_DISTANCE);
	// robot->drop();
}

void AutonomousController::canScoreAccumulate() {
	canScore();
	accumulateFromScore();
}

void AutonomousController::accumulate() {
	robot->driveDistance(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
	robot->lift(LIFT_DISTANCE);
	robot->rotateAngle(180);
	robot->driveDistance(AUTO_GRAY_DISTANCE);
	// robot->drop();
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
}

//Empty destructor
AutonomousController::~AutonomousController() {}
