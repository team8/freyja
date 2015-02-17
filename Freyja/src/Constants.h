#ifndef CONSTANTS_H
#define CONSTANTS_H

//ports for drive train talons
#define PORT_DRIVE_VIC_LEFT_FRONT 0
#define PORT_DRIVE_VIC_LEFT_BACK 1
#define PORT_DRIVE_VIC_RIGHT_FRONT 2
#define PORT_DRIVE_VIC_RIGHT_BACK 3

//Joystick ports
#define PORT_SPEED 1
#define PORT_TURN 2
#define PORT_OPERATOR 0

#define PORT_ENCODER_RIGHT_A 3
#define PORT_ENCODER_RIGHT_B 2
#define PORT_ENCODER_LEFT_A 1
#define PORT_ENCODER_LEFT_B 0

// Solenoid Ports
#define SOLENOID_1_PORT_A 0
#define SOLENOID_1_PORT_B 1
#define SOLENOID_2_PORT_A 2
#define SOLENOID_2_PORT_B 3

#define PORT_AUTO_DIAL 1

#define PORT_GYRO 0

#define LEFT_PROPORTIONAL 0.12
#define LEFT_INTEGRAL 0.0
#define LEFT_DERIVATIVE 0.1

#define RIGHT_PROPORTIONAL 0.12
#define RIGHT_INTEGRAL 0.0
#define RIGHT_DERIVATIVE 0.1

#define GYRO_PROPORTIONAL 0.12
#define GYRO_INTEGRAL 0.0
#define GYRO_DERIVATIVE 0.1

#define ENCODER_MAX_PERIOD 100

#define PID_ASSISTED_TIME_CONSTANT 50

#define RIGHT_DPP 1
#define LEFT_DPP 1

#define LIFT_SPEED 0.5

#define TOTE_HEIGHT 12.1

#endif /* CONSTANTS_H */
