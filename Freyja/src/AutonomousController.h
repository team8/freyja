/*
 * Version 6
 * 1/29/15
 * Jonathan Zwiebel
 */

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

	private:
		enum Path {
			STOP = 0,
			DRIVE = 1,
			TOTE_SCORE = 2,
			TOTE_SCORE_ACCUMULATE = 3,
			TOTE_SCORE_DOUBLE_LEFT = 4,
			TOTE_SCORE_DOUBLE_RIGHT = 5,
			TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE = 6,
			TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE = 7,
			TOTE_SCORE_TRIPLE = 8,
			CAN_SCORE = 9,
			CAN_SCORE_ACCUMULATE = 10,
			ACCUMULATE = 11,
			ACCUMULATE_DOUBLE = 12,
			ACCUMULATE_TRIPLE = 13,
		} path;


		enum AutoCommand {
			CMD_STOP = 0,
			CMD_DRIVE = 1,
			CMD_TOTE_SCORE = 2,
			CMD_TOTE_SCORE_ACCUMULATE = 3,
			CMD_TOTE_SCORE_DOUBLE_LEFT = 4,
			CMD_TOTE_SCORE_DOUBLE_RIGHT = 5,
			CMD_TOTE_SCORE_DOUBLE_LEFT_ACCUMULATE = 6,
			CMD_TOTE_SCORE_DOUBLE_RIGHT_ACCUMULATE = 7,
			CMD_TOTE_SCORE_TRIPLE = 8,
			CMD_CAN_SCORE = 9,
			CMD_CAN_SCORE_ACCUMULATE = 10,
			CMD_ACCUMULATE = 11,
			CMD_ACCUMULATE_DOUBLE = 12,
			CMD_ACCUMULATE_TRIPLE = 13,
			CMD_ACCUMULATE_FROM_SCORE = 14,
			CMD_TOTE_TO_TOTE_RIGHT = 15,
			CMD_TOTE_TO_TOTE_LEFT = 16,
		} command;

		Timer time;
		Robot* robot;
		AnalogInput dial;

		void init();
		void init(int p);
		void update();
		void callCommand(AutoCommand nc);

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
