/*
 * Version 7
 * 2/3/15
 * Jonathan Zwiebel
 */

#ifndef SRC_AUTONOMOUSEXECUTOR_H_
#define SRC_AUTONOMOUSEXECUTOR_H_

// Distance constants used specifically for autonomous
#define YELLOW_AUTO_DISTANCE 0 // y: front of yellow tote to auto zone
#define AUTO_GRAY_DISTANCE 0 // y: auto zone to landfill tote
#define GRAY_GRAY_DISTANCE 0 // x: between totes in landfill zone
#define YELLOW_YELLOW_DISTANCE 0 // x: between yellow auto totes
#define LIFT_DISTANCE 0 // z: lift distance

#include <WPILib.h>
#include <stack>
#include "AutonomousController.h"
#include "Robot.h"
#include "Constants.h"

class AutonomousExecutor {
public:
	AutonomousExecutor(Robot *robotPointer, std::stack<AutonomousController::AutoCommand> *commandStack);
	void executeCommand(AutonomousController::AutoCommand command);
	virtual ~AutonomousExecutor();
private:
	Robot* robot;
	std::stack<AutonomousController::AutoCommand>* commandStack;
	void drive(int dist);
	void lift();
	void drop();
	void toteScore();
	void accumulateFromAuto();
	void toteToTote(bool isLeft);
	void canScore();
	void grayToGray();
	void rotate(int angle);
	void canLift();
};

#endif /* SRC_AUTONOMOUSEXECUTOR_H_ */
