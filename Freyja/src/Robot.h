#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include "DriveTrain.h"

class Robot {
	private:
		DriveTrain driveTrain;
	public:
		Robot();
		void init();
		void update();
		void disable();
};

#endif /* SRC_ROBOT_H_ */
