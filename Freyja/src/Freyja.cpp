#include <WPILib.h>
#include "AutonomousController.h"
#include "HumanController.h"
#include "Robot.h"

/**
 * Interprets the state of the robot and relays the commands
 * to the robot controllers
 * Implements all the WPI Iterative Robot methods
 */
class Freyja: public IterativeRobot {
private:
	Robot robot;
	//Controls the robot during autonomous
	AutonomousController autoController;
	//Controls the robot during teleop
	HumanController humanController;

public:
	Freyja();
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
};

using namespace std;

Freyja::Freyja() :
		//Calls the constructors for the robot and controllers
		autoController(&robot), humanController(&robot) {
}

/** Called when the robot starts */
void Freyja::RobotInit() {
	robot.init();
}

/** Called as the robot is disabled */
void Freyja::DisabledInit() {
	robot.disable();
}

/** Called repeatedly while the robot is disabled */
void Freyja::DisabledPeriodic() {
	robot.disable();
	robot.update();
}
/** Prepares the robot for teleop */
void Freyja::TeleopInit() {
	robot.init();
}

/** Called repeatedly during teleop periodic */
void Freyja::TeleopPeriodic() {
	humanController.update();
	robot.update();
}

/** Initializes the robot for autonomous */
void Freyja::AutonomousInit() {
	robot.init();
	autoController.init();
}
/** Called repeatedly while autonomous is running */
void Freyja::AutonomousPeriodic() {
	autoController.update();
	robot.update();
}

START_ROBOT_CLASS(Freyja);
