#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <WPILib.h>
#include <algorithm>
#include "Subsys.h"
#include "Constants.h"

class Drivetrain: public Subsys {
private:
	Victor leftTopTalon;
//	Victor leftMiddleTalon;
	Victor leftBottomTalon;

	Victor rightTopTalon;
//	Victor rightMiddleTalon;
	Victor rightBottomTalon;

	double targetSpeed;
	double rotateSpeed;

	Encoder leftEncoder;
	Encoder rightEncoder;

	Gyro gyro;

	PIDController leftTopController;
//	PIDController leftMiddleController;
	PIDController leftBottomController;

	PIDController rightTopController;
//	PIDController rightMiddleController;
	PIDController rightBottomController;

public:
	Drivetrain();
	virtual ~Drivetrain();

	void init();

	void disable();

	void update();

	void stopTalons();

	void setSpeed(double targetSpeed, double rotateSpeed);

	void setTargetSpeed(double speed);
	void setRotateSpeed(double speed);

	void rotateAngle(double angle);

	void driveDistance(double distance);
};

#endif /* DRIVETRAIN_H */
