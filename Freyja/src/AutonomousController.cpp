/*
 * Version 8
 * 2/6/15
 * Jonathan Zwiebel
 */


#include "AutonomousController.h"
using namespace std;

AutonomousController::AutonomousController(Robot *robotPointer) :
	dial((uint32_t) PORT_AUTO_DIAL)
{
	path = (Path) dial.GetValue();
	command = CMD_STOP;
	executor = new AutonomousExecutor(*robotPointer, & commandStack);
	executing = false;
}

void AutonomousController::init() {
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
		case TOTE_SCORE_DOUBLE_LEFT:
			toteScoreDoubleLeft();
			break;
		case TOTE_SCORE_DOUBLE_RIGHT:
			toteScoreDoubleRight();
			break;
		case CAN_SCORE:
			canScore();
			break;
		}
}

void AutonomousController::update() {
	if(!executing) {
		command = commandStack.top(); //fetch
		executor->executeCommand(command); // execute
		commandStack.pop(); // increment
		executing = true;
	}
}

void AutonomousController::stop() {
	path = STOP;
	command = CMD_STOP;
	executing = false;
}

void AutonomousController::drive() {
	commandStack.push(CMD_STOP);
	commandStack.push(CMD_FORWARD_DRIVE);
}

void AutonomousController::toteScore() {
	commandStack.push(CMD_STOP);
	commandStack.push(CMD_TOTE_SCORE);
}

void AutonomousController::toteScoreDoubleLeft() {
	commandStack.push(CMD_STOP);
	commandStack.push(CMD_TOTE_SCORE);
	commandStack.push(CMD_TOTE_TO_TOTE_LEFT);
	commandStack.push(CMD_LIFT);
}

void AutonomousController::toteScoreDoubleRight() {
	commandStack.push(CMD_STOP);
	commandStack.push(CMD_TOTE_SCORE);
	commandStack.push(CMD_TOTE_TO_TOTE_RIGHT);
	commandStack.push(CMD_LIFT);
}

void AutonomousController::canScore() {
	commandStack.push(CMD_STOP);
	commandStack.push(CMD_CAN_SCORE);
}

void AutonomousController::accumulateGray() {
	commandStack.push(CMD_STOP);
	commandStack.push(CMD_DRIVE_LANDFILL_AUTO);
	commandStack.push(CMD_HALF_ROTATE);
	commandStack.push(CMD_GRAY_FROM_GRAY);
	commandStack.push(CMD_GRAY_FROM_GRAY);
	commandStack.push(CMD_LANDFILL_DRIVE);
}

//Empty destructor
AutonomousController::~AutonomousController() {}
