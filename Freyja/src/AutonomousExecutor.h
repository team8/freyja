/*
 * Version 11
 * 2/17/15
 * Jonathan Zwiebel and Nihar Mitra
 */

#ifndef FREYJA_SRC_AUTONOMOUSEXECUTOR_H_
#define FREYJA_SRC_AUTONOMOUSEXECUTOR_H_

// Distance constants used specifically for autonomous
#define YELLOW_AUTO_DISTANCE 130 // y: front of yellow tote to auto zone
#define AUTO_GRAY_DISTANCE 75 // y: auto zone to landfill tote
#define GRAY_GRAY_DISTANCE 20 // x: between totes in landfill zone
#define YELLOW_YELLOW_DISTANCE 78 // x: between yellow auto totes
#define LIFT_DISTANCE 10 // z: lift distance
#define TEMPORARY_DRIVE_CONSTANT 50
#define BACK_OUT_DISTANCE 5
#define FRONT_IN_DISTANCE 5

#include <WPILib.h>
#include <list>
#include <iterator>
#include "Robot.h"
#include "Constants.h"
#include "Arm.h"

class AutonomousExecutor {
public:
	AutonomousExecutor(Robot *robotPointer, std::list<AutoCommand> *commandSet);
	void executeCommand(AutoCommand command);
	virtual ~AutonomousExecutor();
	bool isAllIdle();
private:
	Robot* robot;
	std::list<AutoCommand>* commandSet;
	std::list<AutoCommand>::iterator comIt;
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
	void open();
	void close();
	void toteLift();
	void visionAccumulate();
};

#endif /* FREYJA_SRC_AUTONOMOUSEXECUTOR_H_ */
