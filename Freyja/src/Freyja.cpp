#include <WPILib.h>
#include "AutonomousController.h"
#include "HumanController.h"
#include "Robot.h"


class Freyja : public IterativeRobot {
private:
	Robot robot;
	HumanController humanController;
	AutonomousController autoController;
public:
	Freyja();

	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TeleopDisabled();

};

Freyja :: Freyja():
	robot(),
	humanController(),
	autoController(&robot)
	{

	}

void Freyja::RobotInit(){
	robot.init();

}

void Freyja::DisabledInit(){
	robot.disable();

}

void Freyja::DisabledPeriodic(){
	robot.disable();
	robot.update();

}

void Freyja::TeleopInit(){
	robot.init();

}

void Freyja::TeleopPeriodic(){
	humanController.update(&robot);
	robot.update();

}

void Freyja::TeleopDisabled(){
	robot.disable();
	robot.update();
}

START_ROBOT_CLASS(Freyja);
