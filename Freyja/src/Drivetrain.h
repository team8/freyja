/**
 * Represents the robot's tank-drive drivetrain
 * The tank drive is controlled by two victors on each side of the robot
 * Both teleop control methods and autonomous methods are implemented
 */
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <WPILib.h>
#include <algorithm>
#include "Subsys.h"
#include "Constants.h"

class Drivetrain: public Subsys {
private:
	//The robot's left talons, or speed controllers
	TalonSRX leftTopTalon;
	TalonSRX leftBottomTalon;

	//The robot's right talons, or speed controllers
	TalonSRX rightTopTalon;
	TalonSRX rightBottomTalon;

	//The two encoders, or distance sensors, of the drivetrain
	Encoder leftEncoder;
	Encoder rightEncoder;

	//The gyroscope, or orientation sensor, of the drivetrain
	Gyro gyro;

	//The PID Controllers of the drivetrain, control loops allowing highly precise and efficient movement
	PIDController leftTopController;
	PIDController leftBottomController;

	PIDController rightTopController;
	PIDController rightBottomController;

//	PIDController leftTopTurn;
//	PIDController leftBottomTurn;
//	PIDController rightTopTurn;
//	PIDController rightBottomTurn;

	//The PID Controllers of the drivetrin's rotation, cotrol loops allowing the rotation of a desired angle
	PIDController leftTopGyroController;
	PIDController leftBottomGyroController;

	PIDController rightTopGyroController;
	PIDController rightBottomGyroController;

	//The forward speed of the robot during teleoperated control
	double targetSpeed;
	//The rotation speed of the robot during teleoperated control
	double rotateSpeed;
	//The raw forward speed to be used in high precision mode
	double rawTargetSpeed;

	// The value returned by the Y-axis of the driver stick
	double acceleration;

	double leftSpeed;
	double rightSpeed;

	double drivingSetpoint;

public:
	//An enum type definition for the state the robot is in
	typedef enum State {
		//A state in which the drivetrain is not moving and is ready to receive commands
		IDLE,
		//A state in which the robot is driving a specified distance through pid control
		DRIVING_DIST,
		//A state in which the robot is rotating a specified angle through pid control
		ROTATING_ANGLE,
		//A state in which the talon speed is set through teleop commands
		DRIVING_TELEOP,
		//A state in which the turning speed is lowered for higher precision
		PRECISION_TRIGGER,
		//A state in which the talons are set to 0
		//Go max speed backwards
		THROTTLE,
		//Higher sensititivity goes faster
		HIGH_SPEED,
		//break
		BRAKE,

		SLOW_COAST
	} State;

	//The State variable created for this instance
	State state;

	Drivetrain();
	virtual ~Drivetrain();

	void init();
	void disable();
	void update();

	void stopControl();
	void stopTalons();

	void setSpeed(double targetSpeed, double rotateSpeed);
	void setTargetSpeed(double speed);
	void setRotateSpeed(double speed);

	void rotateAngle(double angle);
	void driveDistance(double distance);

	void setStateTrigger();
	void setStateThrottle();
	void setStateHighSpeed();
	void setStateBrake();
	State getState();
};

#endif /* DRIVETRAIN_H */
