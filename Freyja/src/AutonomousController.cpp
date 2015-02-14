/*
 * Version 9
 * 2/13/15
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
	executor = new AutonomousExecutor(*robotPointer, & commandSet);
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
// commandSet and sends it to the executor
// the reason for using this instead of just method calls is so that autonomous
// is controlled periodically and will only function when the update method is
// called
void AutonomousController::update() {
	if(!executing) {
		command = commandSet.back(); //fetch
                executing = true;
		executor->executeCommand(command); // execute
		commandSet.pop_back(); // increment
	}
}

void AutonomousController::stop() {
	path = STOP;
	command = CMD_STOP;
	executing = false;
}

void AutonomousController::drive() {
	commandSet.push_back(CMD_STOP);
	commandSet.push_back(CMD_AUTO_DRIVE);
}

void AutonomousController::toteScore() {
	commandSet.push_back(CMD_STOP);
	commandSet.push_back(CMD_TOTE_SCORE);
}

void AutonomousController::toteScoreDoubleLeft() {
	commandSet.push_back(CMD_STOP);
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_TOTE_TO_TOTE_LEFT);
	commandSet.push_back(CMD_LIFT);
}

void AutonomousController::toteScoreDoubleRight() {
	commandSet.push_back(CMD_STOP);
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_TOTE_TO_TOTE_RIGHT);
	commandSet.push_back(CMD_LIFT);
}

void AutonomousController::canScore() {
	commandSet.push_back(CMD_STOP);
	commandSet.push_back(CMD_CAN_SCORE);
}

void AutonomousController::accumulateGray() {
	commandSet.push_back(CMD_STOP);
	commandSet.push_back(CMD_DRIVE_LANDFILL_AUTO);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_GRAY_TO_GRAY);
	commandSet.push_back(CMD_GRAY_TO_GRAY);
	commandSet.push_back(CMD_LANDFILL_DRIVE);
}

//Empty destructor
AutonomousController::~AutonomousController() {}
