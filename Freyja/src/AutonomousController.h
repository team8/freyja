/*
 * Version 7
 * 2/3/15
 * Jonathan Zwiebel
 */

#ifndef AUTONOMOUS_CONTROLLER_H
#define AUTONOMOUS_CONTROLLER_H


#include <WPILib.h>
#include <stack>
#include "Robot.h"
#include "Constants.h"
#include "AutonomousExecutor.h"

class AutonomousController {
	public:
		AutonomousController(Robot *robotPointer);
		virtual ~AutonomousController();

		// The separate paths that can be run during autonomous, delegated by dial value, will remain constant
		// for entire auto period
		enum Path {
			STOP, DRIVE, TOTE_SCORE, TOTE_SCORE_ACCUMULATE, TOTE_SCORE_DOUBLE_LEFT, TOTE_SCORE_DOUBLE_RIGHT,
			TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE, TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE, CAN_SCORE,
			CAN_SCORE_ACCUMULATE, ACCUMULATE_GRAY
		} path;

		// The current command that is being executed on the robot, this will change throughout auto
		enum AutoCommand {
			CMD_STOP, CMD_FORWARD_DRIVE, CMD_LIFT, CMD_DROP, CMD_TOTE_SCORE, CMD_ACCUMULATE_FROM_AUTO, CMD_TOTE_TO_TOTE_LEFT,
			CMD_TOTE_TO_TOTE_RIGHT, CMD_CAN_SCORE, CMD_DRIVE_LANDFILL_AUTO, CMD_GRAY_FROM_GRAY, CMD_HALF_ROTATE, CMD_LANDFILL_DRIVE
		} command;

	private:
		std::stack<AutoCommand> commandStack;

		bool executing;

		AutonomousExecutor* executor;
		AnalogInput dial;

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
};

#endif /* AUTONOMOUS_CONTROLLER_H */
