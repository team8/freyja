#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "Drivetrain.h"
#include "Arm.h"
#include "Lifter.h"

class Robot {
	private:
		Drivetrain driveTrain;
		Arm arm;
		Lifter lifter;
	public:
		Robot();
		void init();
		void update();
		void disable();
		void move(double y, double x);
		//void changeArmState(uint32_t button);


};

#endif /* SRC_ROBOT_H_ */
