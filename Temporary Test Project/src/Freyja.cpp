class Freyja: public IterativeRobot {
private:
//	Robot robot;
//	HumanController humanController;
//	AutonomousController autoController;

public:
	Freyja();
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
};

Freyja::Freyja():
//	robot(), humanController(&robot), autoController(&robot) {
}

void Freyja::RobotInit() {
//	robot.init();
}

void Freyja::AutonomousInit() {
//	robot.init();
}

void Freyja::AutonomousPeriodic() {
//	autoController.update();
//	robot.update();
}

void Freyja::AutonomousDisabled() {
}

void Freyja::DisabledInit() {
//	robot.disable();
}

void Freyja::DisabledPeriodic() {
//	robot.disable();
//	robot.update();
}

void Freyja::TeleopInit() {
//	robot.init();
}

void Freyja::TeleopPeriodic() {
//	humanController.update();
//	robot.update();
}

void Freyja::TeleopDisabled() {
//	robot.disable();
//	robot.update();
}

void Freyja::TestInit() {
}

void Freyja::TestPeriodic() {
}

//START_ROBOT_CLASS(Freyja);
