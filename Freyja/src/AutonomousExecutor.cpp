/*
 * Version 7
 * 2/3/15
 * Jonathan Zwiebel
 */
#include "AutonomousExecutor.h"
#include <WPILib.h>
#include <stack>
#include "AutonomousController.h"
#include "Robot.h"
#include "Constants.h"

AutonomousExecutor::AutonomousExecutor(Robot *robotPointer, std::stack<AutonomousController::AutoCommand> *commandStack) {
	this->robot = robotPointer;
	this->commandStack = commandStack;
}

void AutonomousExecutor::executeCommand(AutonomousController::AutoCommand command) {
	switch(command) {
	case AutonomousController::CMD_STOP: {
		break;
	}
	case AutonomousController::CMD_FORWARD_DRIVE: {
		break;
	}
	case AutonomousController::CMD_LIFT: {
		break;
	}
	case AutonomousController::CMD_DROP: {
		break;
	}
	case AutonomousController::CMD_TOTE_SCORE: {
		break;
	}
	case AutonomousController::CMD_ACCUMULATE_FROM_AUTO: {
		break;
	}
	case AutonomousController::CMD_TOTE_TO_TOTE_LEFT: {
		break;
	}
	case AutonomousController::CMD_TOTE_TO_TOTE_RIGHT: {
		break;
	}
	case AutonomousController::CMD_CAN_SCORE: {
		break;
	}
	case AutonomousController::CMD_DRIVE_LANDFILL_AUTO: {
		break;
	}
	case AutonomousController::CMD_GRAY_FROM_GRAY: {
		break;
	}
	case AutonomousController::CMD_ROTATE: {
		break;
	}
	case AutonomousController::CMD_LANDFILL_DRIVE: {
		break;
	}
	}
}

AutonomousExecutor::~AutonomousExecutor() {
	// TODO Auto-generated destructor stub
}

