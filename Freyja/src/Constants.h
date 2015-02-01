#ifndef CONSTANTS_H
#define CONSTANTS_H

//ports for drive train victors (currently fenrir), needs to be changed to talons
#define PORT_DRIVE_VIC_LEFT_FRONT 5
#define PORT_DRIVE_VIC_LEFT_BACK 6
#define PORT_DRIVE_VIC_RIGHT_FRONT 1
#define PORT_DRIVE_VIC_RIGHT_BACK 2

//Joystick ports
#define PORT_SPEED 1
#define PORT_TURN 2
#define PORT_OPERATOR 3

#define PORT_ENCODER_RIGHT_A 1
#define PORT_ENCODER_RIGHT_B 2
#define PORT_ENCODER_LEFT_A 5
#define PORT_ENCODER_LEFT_B 6

#define PORT_AUTO_DIAL 9

#define PORT_GYRO 0

#define LEFT_PROPORTIONAL 0.12
#define LEFT_INTEGRAL 0.0
#define LEFT_DERIVATIVE 0.1

#define RIGHT_PROPORTIONAL 0.12
#define RIGHT_INTEGRAL 0.0
#define RIGHT_DERIVATIVE 0.1

#define STOPPED_DRIVE_DIFF 0.1

#define PID_ASSISTED_TIME_CONSTANT 50

#define RIGHT_DPP 0.079943744109167
#define LEFT_DPP 0.082290358410833

#define LIFT_SPEED 0.5

#define LIFT_SPEED 0.5

#endif /* CONSTANTS_H */
