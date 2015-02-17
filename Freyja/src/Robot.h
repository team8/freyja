/**
 * Represents the robot
 * Contains three subsystems, arm, drivetrain, and lifter
 * Initializes, disables, and updates these subsystems
 * Has wrapper methods that delegate tasks to subsystems
 */
#ifndef ROBOT_H
#define ROBOT_H

#include "Drivetrain.h"
#include "Arm.h"
#include "Lifter.h"

class Robot {
	private:
		//The drivetrain, arm, and lifter subsystems
		Drivetrain drivetrain;
		Arm arm;
		Lifter lifter;

	public:
		/** Robot constructor, initializes robot and subsystems */
		Robot();

		/** Initializes instance and subsystems */
		void init();
		/** Updates instance and subsystems */
		void update();
		/** Disables instance and subsystems */
		void disable();

		/** Wrapper method for drivetrain teleoperated movement */
		void move(double targetSpeed, double rotateSpeed);

		/** Wrapper method for changing piston state */
		void changePistonState(Arm::PistonState state);

		/** Wrapper method for changing the compressor state */
		void changeCompressorState(Arm::CompressorState state);

		/** Wrapper method for driving a specified distance */
		void driveDistance(double distance);

		/** Wrapper method for rotating a specified angle */
		void rotateAngle(double angle);

		/** Wrapper method for changing the Drivetrain state to PRECISION_TRIGGER*/
		void changeDrivetrainStateToPRECISION_TRIGGER();

		/** Wrapper method for changing the Drivetrain state to BRAKE*/
		void changeDrivetrainStateToBRAKE();

		/** Wrapper method for lifting a specified distance */
		void lift();
		void drop();
		void canLift();

		/** Wrapper method for setting the lifter level */
		void setLifterLevel(int level);

		Drivetrain::State getDrivetrainState();
		Lifter::State getLifterState();

		/**Wrapper method for zeroing the lifter level **/
		void zeroLifter();
		/**Wrapper method for getting the current level of the lifter**/
		double getLevel();
<<<<<<< HEAD
=======

		void setLifter(double speed);
>>>>>>> 31ceff6c53440b7e2b43cd83b17bf93cd7237c32
};

#endif /* ROBOT_H */
