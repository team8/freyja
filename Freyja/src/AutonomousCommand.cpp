/*
 * AutonomousCommand.cpp
 */

#include <AutonomousCommand.h>

AutonomousCommand::AutonomousCommand():
	operations()
{

}

AutonomousCommand::~AutonomousCommand() {

}

void AutonomousCommand::add(void (*operation)(double)) {
	operations.push(*operation);
}

std::queue<void (double)> AutonomousCommand::getOperations() {
	return operations;
}
