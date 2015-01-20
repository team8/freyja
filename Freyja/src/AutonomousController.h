/*
 * Version 4
 * 1/19/15 at 2300
 * Jonathan Zwiebel
 */


#ifndef SRC_AUTONOMOUSCONTROLLER_H_
#define SRC_AUTONOMOUSCONTROLLER_H_
#define PATH 0
#define DEFAULT_DRIVE_DISTANCE 20
#include <WPILib.h>
#include "Robot.h"
#include "Timer.h"

class AutonomousController {
	public:
		AutonomousController(Robot *robotPointer);
		virtual ~AutonomousController();
		int path;
	private:
		Timer time;
		Robot* robot;
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
		void accumulateFromScore();
	};

#endif
