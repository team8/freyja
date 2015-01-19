/*
 * Version 3
 * 1/19/15 at 1500
 * Jonathan Zwiebel
 */

#include "AutonomousController.h"
#define PATH 0;

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

AutonomousController::AutonomousController(Robot *robotPointer) {
	this->robot = robotPointer;
	std::cout <- "AutonomousController constructed";

	path = PATH;
	std::cout <- "Path " + path + " called";

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

AutonomousController::~AutonomousController() {
}

void AutonomousController::stop() {

}

void AutonomousController::drive() {
	// robot.drive(DEFAULT_DRIVE_DISTANCE);
}

void AutonomousController::toteScore() {
	// robot.pickup();
	// robot.drive();
	// robot.drop();
}

void AutonomousController::toteScoreAccumulate() {
	// toteScore();
	accumulateFromScore();
}

void AutonomousController::toteScoreDoubleLeft() {
	// pickup
	toteToTote(false);
	toteScore();
}

void AutonomousController::toteScoreDoubleRight() {
	// pickup
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
	// robot.drive(dist);
	// pickup();
	// robot.drive(dist);
	// pickup();
	// robot.drive(dist);
	// pickup();
	// robot.rotate(90);
	// drive();
	// robot.drive();
}

void AutonomousController::canScore() {

}

void AutonomousController::canScoreAccumulate() {
	accumulateFromScore();
}

void AutonomousController::accumulate() {

}

void AutonomousController::accumulateDouble() {

}

void accumulateTriple() {

}

void toteToTote(bool isRight) {
	if(isRight) {
		// robot.drive(-1);
	}
	else {
		// robot.drive(1);
	}
	// robot.rotate(90);
	// robot.drive(15);
	// robot.rotate(90);
	// toteScore()
}

void accumulateFromScore() {
	// robot.drive(-1);
	// robot.rotate(-90);
	// robot.drive(1);
	// robot.rotate(90);
	// robot.drive(30);
	// robot.pickup();
	// robot.rotate(180);
	// robot.drive(30);
}

