#include <WPILib.h>
#include "AutonomousController.h"
#include "HumanController.h"
#include "Robot.h"

/**
 * The class describing the robot and its controllers
 * Implements WPI class of Iterative Robot, and appropriate functions
 */
class Freyja: public IterativeRobot {
private:
	/** The field representing the robot **/
	Robot robot;
	/** The field representing the human controller **/
	HumanController humanController;
	/** The field representing the autonomous controller **/
	AutonomousController autoController;
public:
	/** The Freyja class constructor **/
	Freyja();

	/** Robot initialization, implemented from iterative robot **/
	void RobotInit();
	/** Disabled period initialization, implemented from iterative robot **/
	void DisabledInit();
	/** Disabled period update, implemented from iterative robot **/
	void DisabledPeriodic();
	/** Teleop period initialization, implemented from iterative robot **/
	void TeleopInit();
	/** Teleop period update, implemented from iterative robot **/
	void TeleopPeriodic();
};

using namespace std;

/** The Freyja class constructor **/
Freyja::Freyja() :
		//Constructor calls for robot, and controllers
		robot(), humanController(), autoController(&robot) {
}

/** Robot initialization, implemented from iterative robot **/
void Freyja::RobotInit() {
	//Initializes robot
	robot.init();
}

/** Disabled period update, implemented from iterative robot **/
void Freyja::DisabledInit() {
	//Disables robot
	robot.disable();
}

/** Disabled period update, implemented from iterative robot **/
void Freyja::DisabledPeriodic() {
	//Disables and updates robot
	robot.disable();
	robot.update();
}
/** Teleop period initialization, implemented from iterative robot **/
void Freyja::TeleopInit() {
	//Initializes robot
	robot.init();
}

/** Teleop period update, implemented from iterative robot **/
void Freyja::TeleopPeriodic() {
	//Updates human controller and robot
	humanController.update(&robot);
	robot.update();
}

START_ROBOT_CLASS(Freyja);
