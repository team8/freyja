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
		break;
	case DRIVE:
		break;
	case TOTE_SCORE:
		break;
	case TOTE_SCORE_ACCUMULATE:
		break;
	case TOTE_SCORE_DOUBLE_LEFT:
		break;
	case TOTE_SCORE_DOUBLE_RIGHT:
		break;
	case TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE:
		break;
	case TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE:
		break;
	case TOTE_SCORE_TRIPLE:
		break;
	case CAN_SCORE:
		break;
	case CAN_SCORE_ACCUMULATE:
		break;
	case ACCUMULATE:
		break;
	case ACCUMULATE_DOUBLE:
		break;
	case ACCUMULATE_TRIPLE:
		break;
	}
}

AutonomousController::~AutonomousController() {
}

void AutonomousController::stop() {

}

void drive() {

}

void toteScore() {

}
void toteScoreAccumulate() {

}

void toteScoreDoubleLeft() {

}

void toteScoreDoubleRight() {

}

void toteScoreDoubleLeftAccumulate() {

}

void toteScoreDoubleRightAccumulate() {

}

void toteScoreTriple() {

}

void canScore() {

}

void canScoreAccumulate() {

}

void accumulate() {

}

void accumulateDouble() {

}

void accumulateTriple() {

}

