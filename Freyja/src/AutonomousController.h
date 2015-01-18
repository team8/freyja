/*
 * Version 2
 * 1/18/15 at 1446
 */

#ifndef SRC_AUTONOMOUSCONTROLLER_H_
#define SRC_AUTONOMOUSCONTROLLER_H_
#define PATH 0

class AutonomousController {
	public:
		AutonomousController(Robot *robotPointer);
		virtual ~AutonomousController();
		int path;
	private:
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
	};

#endif
