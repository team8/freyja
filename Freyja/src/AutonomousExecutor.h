/*
 * Version 7
 * 2/3/15
 * Jonathan Zwiebel
 */

#ifndef SRC_AUTONOMOUSEXECUTOR_H_
#define SRC_AUTONOMOUSEXECUTOR_H_

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
};

#endif /* SRC_AUTONOMOUSEXECUTOR_H_ */
