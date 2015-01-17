#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include "Drivetrain.h"

class Robot {
	private:
		Drivetrain driveTrain;
		Arm arm;
	public:
		Robot();
		void init();
		void update();
		void disable();
		void move(double y, double x);
};

#endif /* SRC_ROBOT_H_ */
