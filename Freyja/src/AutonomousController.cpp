/*
 * Version 2
 * 1/18/15 at 1446
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
	path = PATH;
	switch(path) {
	case STOP:
		stop();
		break;
	case DRIVE:
		drive(DEFAULT_DRIVE_DISTANCE);
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

void AutonomousController::drive(int dist) {
	// robot.drive(dist);
	// stop();
}

void AutonomousController::toteScore() {
	// robot.pickup();
	// robot.drive(dist);
	// robot.drive();
	// stop();
}

void AutonomousController::toteScoreAccumulate() {
	// toteScore();
	// robot.drive(-1);
	// robot.rotate(-90);
	// robot.drive(1);
	// robot.rotate(90);
	// robot.drive(30);
	// robot.pickup();
	// robot.rotate(180);
	// robot.drive(30);
}

void AutonomousController::toteScoreDoubleLeft() {
	// pickup
	// robot.drive(-1);
	// robot.rotate(-90);
	// robot.drive(15);
	// robot.rotate(90);
	// toteScore()
}

void AutonomousController::toteScoreDoubleRight() {
	// pickup
	// robot.drive(-1);
	// robot.rotate(90);
	// robot.drive(15);
	// robot.rotate(90);
	// toteScore()

}

void AutonomousController::toteScoreDoubleLeftAccumulate() {
	// pickup
	// robot.drive(-1);
	// robot.rotate(-90);
	// robot.drive(15);
	// robot.rotate(90);
	// toteScore()
}

void AutonomousController::toteScoreDoubleRightAccumulate() {

}

void AutonomousController::toteScoreTriple() {

}

void AutonomousController::canScore() {

}

void AutonomousController::canScoreAccumulate() {

}

void AutonomousController::accumulate() {

}

void AutonomousController::accumulateDouble() {

}

void accumulateTriple() {

}

void accumulateFromScore() {

}

