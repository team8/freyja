/*
 * Version 11
 * 2/17/15
 * Jonathan Zwiebel and Nihar Mitra
 */

#include "AutonomousController.h"
using namespace std;

// constructs the analog dial and sets the path to the one being used
// then sets the original command to stop and creates the executor

// DIAL CURRENTLY COMMENTED OUT
AutonomousController::AutonomousController(Robot *robotPointer) :
		executor(robotPointer, &commandSet), udpListener { "4950" }
//dial((uint32_t) PORT_AUTO_DIAL)
{
	//path = (Path) dial.GetValue();
	path = TOTE_SCORE;
	//initial command
	command = CMD_STOP;
	executing = false;
	distance = 0;
	angle = 0;
	robotPointer->init();
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
	//network with rPi to offsource vision

//	std::string msg = udpListener.recv();
//	if (msg != UDP_Listener::RECV_ERROR) {
//			std::string::size_type sz;
//			distance = std::stod(msg, &sz);
//			angle = std::stod(msg.substr(sz));
//			std::cout << "distance: " << distance << "    angle: " << angle << std::endl;
//	}

	std::cout << "executing: " << executing << std::endl;

	// loops only when there is no command currently running
	if(executor.isAllIdle() && !executing) {
		std::cout << commandSet.front() << std::endl;
		command = commandSet.front(); //fetch - gets the command to run
		executing = true;
		executor.executeCommand(command); // execute - runs the command
		// conditional to prevent null reference error
		if(!commandSet.empty()) {
			std::cout << "pop pop" << endl;
			commandSet.pop_front(); // increment - sets the next command run to run
		} else {
			std::cout << "commandSet empty" << std::endl;
			executing = false;
			// turns off the loop
		}
	}
	// checks if everything is idle, meaning nothing is running
	else if(executor.isAllIdle()) {
		cout << "all idle, executing to true" << endl;
		executing = false;
	}
}

// dead stop path
void AutonomousController::stop() {
	path = STOP;
	command = CMD_STOP;
	executing = true;
}

// drives into auto zone
void AutonomousController::drive() {
	commandSet.push_back(CMD_AUTO_DRIVE);
	commandSet.push_back(CMD_STOP);
}

// scores a single yellow tote
void AutonomousController::toteScore() {
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_STOP);
}

// scores a yellow tote and the one to its left
void AutonomousController::toteScoreDoubleLeft() {
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_VISION_ACCUMULATE);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_AUTO_DRIVE);
	commandSet.push_back(CMD_STOP);
}

// scores a yellow tote and the one to its right
void AutonomousController::toteScoreDoubleRight() {
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_VISION_ACCUMULATE);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_AUTO_DRIVE);
	commandSet.push_back(CMD_STOP);
}

// scores an auto can on our side
void AutonomousController::canScore() {
	commandSet.push_back(CMD_CAN_SCORE);
	commandSet.push_back(CMD_STOP);
}

// goes to the landfill zone, accumulates gray totes and ends in auto zone
void AutonomousController::accumulateGray() {
	commandSet.push_back(CMD_FRONT_IN);
	commandSet.push_back(CMD_CLOSE);
	commandSet.push_back(CMD_BACK_OUT);
	commandSet.push_back(CMD_HALF_ROTATE);
	commandSet.push_back(CMD_DRIVE_LANDFILL_AUTO);
	commandSet.push_back(CMD_STOP);
}

// special path used for testing
void AutonomousController::test() {
	commandSet.push_back(CMD_TOTE_SCORE);
	commandSet.push_back(CMD_STOP);
}

//Empty destructor
AutonomousController::~AutonomousController() {
}
