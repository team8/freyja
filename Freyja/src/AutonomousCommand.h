/*
 * AutonomousCommand.h
 */


#ifndef SRC_AUTONOMOUSCOMMAND_H_
#define SRC_AUTONOMOUSCOMMAND_H_

#include <iostream>
#include <queue>

class AutonomousCommand {
	private:
		std::queue<void (double)> operations;

	public:
		AutonomousCommand();
		virtual ~AutonomousCommand();

		void add(void (*operation)(double));

		std::queue<void (double)> getOperations();
};

#endif /* SRC_AUTONOMOUSCOMMAND_H_ */
