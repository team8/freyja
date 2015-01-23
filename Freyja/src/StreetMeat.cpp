/*
 * Robot.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: EngTechP7
 */

// 0.047 is error degrees per pulse is approximate


#include <iostream>
#include "WPILib.h"

class StreetMeat : public IterativeRobot {

  public:
    StreetMeat();
    void RobotInit();
	  void AutonomousInit();
	  void AutonomousPeriodic();
	  void AutonomousDisabled();
	  void DisabledInit();
	  void DisabledPeriodic();
	  void TeleopInit();
	  void TeleopPeriodic();
	  void TeleopDisabled();
	  void TestInit();
	  void TestPeriodic();
  private:
    Gyro gyro;
    float calib;
    double a = 0;
    int c = 0;
    int b = 0;
};

StreetMeat::StreetMeat():
	gyro((uint32_t)1)
{
	calib = 0;
}

void StreetMeat::RobotInit() {

}

void StreetMeat::AutonomousInit() {

}

void StreetMeat::AutonomousPeriodic() {

}

void StreetMeat::AutonomousDisabled() {
}

void StreetMeat::DisabledInit() {

}

void StreetMeat::DisabledPeriodic() {

}

void StreetMeat::TeleopInit() {
	std::cout << "Delicious!" << std::endl;
	gyro.Reset();
}

void StreetMeat::TeleopPeriodic() {
	c++;
	std::cout << gyro.GetAngle() - a << "  ";
	a = gyro.GetAngle();
	if(c % 10 == 0) {
		std::cout << gyro.GetAngle() - b << std::endl;
		b = gyro.GetAngle();
	}
}

void StreetMeat::TeleopDisabled() {
}

void StreetMeat::TestInit() {
}

void StreetMeat::TestPeriodic() {

};

START_ROBOT_CLASS(StreetMeat);
