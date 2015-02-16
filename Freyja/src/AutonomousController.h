/*
 * Version 10
 * 2/14/15
 * Jonathan Zwiebel
 */

#ifndef AUTONOMOUS_CONTROLLER_H
#define AUTONOMOUS_CONTROLLER_H


#include <WPILib.h>
#include <list>
#include "Robot.h"
#include "Constants.h"
#include "AutonomousExecutor.h"


class AutonomousController {
	public:
		AutonomousController(Robot *robotPointer);
		virtual ~AutonomousController();

	private:
                // the ordered list of commands, will be changed to a List soon
		std::list<AutoCommand> commandSet;

                // tracks whether the executor is actively functioning
		bool executing;

		AutonomousExecutor executor;
		//AnalogInput dial;

		Path path;
		AutoCommand command;

		void update();
		void init();
		void callCommand(AutoCommand nc);

		void stop();
		void drive();
		void toteScore();
		void toteScoreAccumulate();
		void toteScoreDoubleLeft();
		void toteScoreDoubleRight();
		void toteScoreDoubleLeftAccumulate();
		void toteScoreDoubleRightAccumulate();
		void canScore();
		void canScoreAccumulate();
		void accumulateGray();
		void test();
};

#endif /* AUTONOMOUS_CONTROLLER_H */
