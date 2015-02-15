/*
 * Version 10
 * 2/14/15
 * Jonathan Zwiebel
 */



#include "AutonomousController.h"
using namespace std;

// constructs the analog dial and sets the path to the one being used
// then sets the original command to stop and creates the executor

// DIAL CURRENTLY COMMENTED OUT
AutonomousController::AutonomousController(Robot *robotPointer) :
		executor(robotPointer, &commandSet)
	//dial((uint32_t) PORT_AUTO_DIAL)
{
	//path = (Path) dial.GetValue();
	path = TEST;
	command = CMD_STOP;
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
		case ACCUMULATE_GRAY:
			accumulateGray();
			break;
		case TEST:
			test();
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
		command = commandSet.front(); //fetch
        executing = true;
		executor.executeCommand(command); // execute
		commandSet.pop_back(); // increment
	}
}

void AutonomousController::stop() {
	path = STOP;
	command = CMD_STOP;
	executing = false;
}

void AutonomousController::drive() {
	commandSet.push_back(CMD_AUTO_DRIVE);
	commandSet.push_back(CMD_STOP);
}

void AutonomousController::toteScore() {
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_STOP);
}

void AutonomousController::toteScoreDoubleLeft() {
	commandSet.push_back(CMD_LIFT);
	commandSet.push_back(CMD_TOTE_TO_TOTE_LEFT);
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_STOP);
}

void AutonomousController::toteScoreDoubleRight() {
	commandSet.push_back(CMD_LIFT);
	commandSet.push_back(CMD_TOTE_TO_TOTE_RIGHT);
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_STOP);
}

void AutonomousController::canScore() {
	commandSet.push_back(CMD_CAN_SCORE);
	commandSet.push_back(CMD_STOP);
}

void AutonomousController::accumulateGray() {
	commandSet.push_back(CMD_LANDFILL_DRIVE);
	commandSet.push_back(CMD_GRAY_TO_GRAY);
	commandSet.push_back(CMD_GRAY_TO_GRAY);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_DRIVE_LANDFILL_AUTO);
	commandSet.push_back(CMD_STOP);
}

void AutonomousController::test() {
	commandSet.push_back(CMD_STOP);
}

//Empty destructor
AutonomousController::~AutonomousController() {}
