#ifndef AUTONOMOUS_CONTROLLER_H
#define AUTONOMOUS_CONTROLLER_H

#define PATH 0

#include <WPILib.h>
#include "Robot.h"
#include "Timer.h"
#include "Constants.h"
#include <AnalogInput.h>


class AutonomousController {
	public:
		AutonomousController(Robot *robotPointer);
		virtual ~AutonomousController();
		int path;

	private:
		Timer time;
		Robot* robot;
		AnalogInput dial;

		//Various drive paths
		void stop();
		void drive();
		void toteScore();
		void toteScoreAccumulate();
		void toteScoreDoubleLeft();
		void toteScoreDoubleRight();
		void toteScoreDoubleLeftAccumulate();
		void toteScoreDoubleRightAccumulate();
		void toteScoreTriple();
		void canScore();
		void canScoreAccumulate();
		void accumulate();
		void accumulateDouble();
		void accumulateTriple();
		void accumulateFromScore();
		void toteToTote(bool isRight);
	};

#endif /* AUTONOMOUS_CONTROLLER_H */
