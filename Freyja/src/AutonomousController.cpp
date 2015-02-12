/*
 * Version 8
 * 2/6/15
 * Jonathan Zwiebel
 */


#include "AutonomousController.h"
using namespace std;

// constructrs the anolog dial and sets the path to the one being used
// then sets the original command to stop and creates the executor
AutonomousController::AutonomousController(Robot *robotPointer) :
	dial((uint32_t) PORT_AUTO_DIAL)
{
	path = (Path) dial.GetValue();
	command = CMD_STOP;
	executor = new AutonomousExecutor(*robotPointer, & commandStack);
	executing = false;
}

// called once at the beginning of autonomous, this sets the robot
// onto the correct path
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

// called periodically throughout autonomous, this pops the top off the
// commandStack and sends it to the executor
// the reason for using this instead of just method calls is so that autonomous
// is controlled periodically and will only function when the update method is
// called
void AutonomousController::update() {
	if(!executing) {
		command = commandStack.top(); //fetch
                executing = true;
		executor->executeCommand(command); // execute
		commandStack.pop(); // increment
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
