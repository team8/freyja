/*
 * Drivetrain.h

 *
 *  Created on: Jan 6, 2015
 *      Author: liam
 */

#include <WPILib.h>
#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_

class Drivetrain {
private:
	//Talons
	Talon topLeftTalon;
	Talon middleLeftTalon;
	Talon bottomLeftTalon;
	Talon topRightTalon;
	Talon middleRightTalon;
	Talon bottomRightTalon;

	double targetSpeed;
	double rotateSpeed;
	double rotateAngel;


public:

	Drivetrain();
	virtual ~Drivetrain();

	void update();

	void stopTalons();

	void runCommand();

	void setSpeed(double spd);

	void rotateAngle(double angle);

	typedef enum DriveState
	{
		Stop_Talons,
	};
};

#endif /* SRC_DRIVETRAIN_H_ */
