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

	//The forward speed of the robot during teleoperated control
	double targetSpeed;
	//The rotation speed of the robot during teleoperated control
	double rotateSpeed;
	
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

	//The PID Controllers of the drivetrin's rotation, cotrol loops allowing the rotation of a desired angle
	PIDController leftTopGyroController;
	PIDController leftBottomGyroController;

	PIDController rightTopGyroController;
	PIDController rightBottomGyroController;

public:
	//An enum type definition for the state the robot is in
	typedef enum State
	{
		//A state in which the drivetrain is not moving and is ready to receive commands
		IDLE,
		//A state in which the robot is driving a specified distance through pid control
		DRIVING_DIST,
		//A state in which the robot is rotating a specified angle through pid control
		ROTATING_ANGLE,
		//A state in which the talon speed is set through teleop commands
		DRIVING_TELEOP,
		//A state in which the turning speed is lowered for higher precision
		PRECISION_TRIGGER
	} State;
	
	//The State variable created for this instance
	State state;
	
	//Constructor declaration, constructs fileds of drivetrain
	Drivetrain();
	
	//Destructor declaration
	virtual ~Drivetrain();

	//Initializes drivetain and associated fields
	void init();

	//Disables drivetrain and associated fields
	void disable();
	
	//Updates the drivetrain and fields
	void update();

	//Stops robot motion and controler output
	void stopControl();

	//Stops all drivetrain motion
	void stopTalons();

	//Sets the target and rotate speed of the robot
	void setSpeed(double targetSpeed, double rotateSpeed);

	//Sets the target and rotate speed of the robot
	void setTargetSpeed(double speed);
	void setRotateSpeed(double speed);

	//Rotates the drivetrain by the given angle, uses gyroscope and pid controllers
	void rotateAngle(double angle);

	//Drives the drivetrain the given distance, uses pid controllers
	void driveDistance(double distance);

	//Set state to PREISION_TRIGGER
	void setStateTrigger();

	//Returns the state of this drivetrain
	State getState();
};

#endif /* DRIVETRAIN_H */
