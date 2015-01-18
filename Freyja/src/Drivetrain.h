/*
 * Drivetrain.h

 *
 *  Created on: Jan 6, 2015
 *      Author: liam
 */


#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_
#include <WPILib.h>
#include "Subsys.h"
#include "Constants.h"

class Drivetrain : public Subsys {
private:
	//Talons
	Victor leftTopTalon;
	//Victor leftMiddleTalon;
	Victor leftBottomTalon;
	Victor rightTopTalon;
	//Victor rightMiddleTalon;
	Victor rightBottomTalon;

	double targetSpeed;
	double rotateSpeed;
	double leftSpeed;
	double rightSpeed;

public:

	Drivetrain();
	virtual ~Drivetrain();

	void init();
	
	void disable();
	
	void update();

	void stopTalons();

	void setSpeed(double spd);

	void rotateAngle(double angle);

	void move(double Y, double X);
};

#endif /* SRC_DRIVETRAIN_H_ */
