#ifndef CONSTANTS_H
#define CONSTANTS_H

//ports for drive train talons
#define PORT_DRIVE_VIC_LEFT_FRONT 2
#define PORT_DRIVE_VIC_LEFT_BACK 3
#define PORT_DRIVE_VIC_RIGHT_FRONT 0
#define PORT_DRIVE_VIC_RIGHT_BACK 1

//Joystick ports
#define PORT_SPEED 1
#define PORT_TURN 2
#define PORT_OPERATOR 0

#define PORT_ENCODER_RIGHT_A 2
#define PORT_ENCODER_RIGHT_B 3
#define PORT_ENCODER_LEFT_A 1
#define PORT_ENCODER_LEFT_B 0

// Solenoid Ports
#define SOLENOID_1_PORT_A 0
#define SOLENOID_1_PORT_B 1
#define SOLENOID_2_PORT_A 2
#define SOLENOID_2_PORT_B 3

#define PORT_AUTO_DIAL 1

#define PORT_GYRO 6

//Various PID constants
//#define LEFT_PROPORTIONAL 0.12
//#define LEFT_INTEGRAL 0.0
//#define LEFT_DERIVATIVE 0.10
//
//#define RIGHT_PROPORTIONAL -0.12
//#define RIGHT_INTEGRAL -0.0
//#define RIGHT_DERIVATIVE -0.1

#define LEFT_PROPORTIONAL 0.12
#define LEFT_INTEGRAL 0.0
#define LEFT_DERIVATIVE 0.1

#define RIGHT_PROPORTIONAL -0.12
#define RIGHT_INTEGRAL -0.0
#define RIGHT_DERIVATIVE -0.1

#define GYRO_PROPORTIONAL 0.12
#define GYRO_INTEGRAL 0.0
#define GYRO_DERIVATIVE 0.1

#define ENCODER_MAX_PERIOD 1

#define PID_ASSISTED_TIME_CONSTANT 50

//Distance per pulse for drivetrain
#define RIGHT_DPP 0.018258776354
#define LEFT_DPP 0.012808296080

#define LIFT_SPEED 0.5
#define TOTE_HEIGHT 12.1

// Constants used for fine tuning steering
// assumes 200 updates per second
#define ACCELERATION_CONSTANT 0.0133
#define SPEED_DECAY_CONSTANT 0.90
#define SPEED_DECAY_RANGE 0.1
#define PRECISION_ROTATE_CONSANT 0.4
#define ROTATE_CONSTANT 0.8
#define ACCELERATION_REVERSE_CONSTANT 0.025

// enums for AutonomousController and AutonomousExecutor
enum Path {
	STOP,
	DRIVE,
	TOTE_SCORE,
	TOTE_SCORE_DOUBLE_LEFT,
	TOTE_SCORE_DOUBLE_RIGHT,
	CAN_SCORE,
	ACCUMULATE_GRAY,
	TEST
};

enum AutoCommand {
	CMD_STOP,
	CMD_AUTO_DRIVE,
	CMD_LIFT,
	CMD_DROP,
	CMD_TOTE_SCORE,
	CMD_ACCUMULATE_FROM_AUTO,
	CMD_TOTE_TO_TOTE_LEFT,
	CMD_TOTE_TO_TOTE_RIGHT,
	CMD_CAN_SCORE,
	CMD_DRIVE_LANDFILL_AUTO,
	CMD_GRAY_TO_GRAY,
	CMD_HALF_ROTATE,
	CMD_LANDFILL_DRIVE,
	CMD_CAN_LIFT,
	CMD_CLOSE,
	CMD_OPEN,
	CMD_TOTE_LIFT
};

#endif /* CONSTANTS_H */
