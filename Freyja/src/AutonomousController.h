/*
 * Version 12
 * 3/23/15
 * Jonathan Zwiebel and Nihar Mitra
 */

#ifndef AUTONOMOUS_CONTROLLER_H
#define AUTONOMOUS_CONTROLLER_H

#include <WPILib.h>
#include <list>
#include <algorithm>
#include "Robot.h"
#include "Constants.h"
#include "AutonomousExecutor.h"

class AutonomousController {
public:
	AutonomousController(Robot *robotPointer);
	virtual ~AutonomousController();
	void update();
	void init();

private:
	// the highest level list of commands, mutates
	std::list<AutoCommand> commandSet;

	// tracks whether the executor is actively functioning
	bool executing;

	AutonomousExecutor executor;
	//AnalogInput dial;

	Path path;
	AutoCommand command;

	// paths
	void stop();
	void drive();
	void toteScore();
	void toteScoreBackwards();
	void toteScoreAccumulate();
	void toteScoreDoubleLeft();
	void toteScoreDoubleRight();
	void toteScoreDoubleLeftAccumulate();
	void toteScoreDoubleRightAccumulate();
	void canScore();
	void canScoreAccumulate();
	void accumulateGray();
	void accumulateGrayDouble();
	void toteScoreDoubleStraight();
	void toteScoreDoubleWiggle();
	void test();
};

#endif /* AUTONOMOUS_CONTROLLER_H */
