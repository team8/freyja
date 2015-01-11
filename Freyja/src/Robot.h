#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include "Drivetrain.h"

class Robot {
	private:
		Drivetrain driveTrain;
	public:
		Robot();
		void init();
		void update();
		void disable();
};

#endif /* SRC_ROBOT_H_ */
