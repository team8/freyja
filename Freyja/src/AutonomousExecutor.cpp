/*
 * Version 11
 * 2/17/15
 * Jonathan Zwiebel and Nihar Mitra
 */

#include <WPILib.h>
#include "AutonomousExecutor.h"
#include <list>
#include "Robot.h"
#include "Constants.h"
#include <iterator>
#include "Arm.h"

using namespace std;

AutonomousExecutor::AutonomousExecutor(Robot *robotPointer,
		list<AutoCommand> *commandSet) :
		udpListener("4950") {
	this->robot = robotPointer;
	this->commandSet = commandSet;
	visDistance = 0;
	visPlanarAngle = 0;
	visRotationalAngle = 0;
}

void AutonomousExecutor::executeCommand(AutoCommand command) {
//	cout << "AutonomousExecutor::executeCommand(" << command << ")" << commandSet->size() << endl;
//	cout << "Vision Planar Angle: " << visPlanarAngle << endl;
//	cout << "Vision Rotational Angle: " << visRotationalAngle << endl;
//	cout << "Vision Distance: " << visDistance << endl;
	switch (command) {
	case CMD_STOP:
		break;
	case CMD_AUTO_DRIVE:
		//std::cout << "CMD_AUTO_DRIVE start" << std::endl;
		drive(YELLOW_AUTO_DISTANCE);
		//	std::cout << "CMD_AUTO_DRIVE end" << std::endl;
		break;
	case CMD_LIFT:
		lift();
		break;
	case CMD_LOWER:
		lower();
		break;
	case CMD_DROP:
		drop();
		break;
		// MACRO: picks up a tote, drives and drops it in the correct zone
	case CMD_TOTE_SCORE:
		toteScore();
		break;
	case CMD_ACCUMULATE_FROM_AUTO:
		accumulateFromAuto();
		break;
	case CMD_TOTE_TO_TOTE_LEFT:
		toteToTote(true);
		break;
	case CMD_TOTE_TO_TOTE_RIGHT:
		toteToTote(false);
		break;
	case CMD_CAN_SCORE:
		canScore();
		break;
	case CMD_DRIVE_LANDFILL_AUTO:
		drive(-AUTO_GRAY_DISTANCE);
		break;
	case CMD_GRAY_TO_GRAY:
		grayToGray();
		break;
	case CMD_HALF_ROTATE:
//		std::cout << "CMD_HALF_ROTATE start" << std::endl;
		rotate(180);
//		std::cout << "CMD_HALF_ROTATE end" << std::endl;
		break;
	case CMD_LANDFILL_DRIVE:
		drive(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
		break;
	case CMD_CAN_LIFT:
		canLift();
		break;
	case CMD_CLOSE:
		close();
		break;
	case CMD_OPEN:
		open();
		break;
	case CMD_TOTE_LIFT:
		toteLift();
		break;
	case CMD_TOTE_STACK:
		toteStack(1 * TOTE_HEIGHT);
		break;
	case CMD_VISION_ACCUMULATE:
		visionAccumulate();
		break;
	case CMD_BACK_OUT:
		drive(-BACK_OUT_DISTANCE);
		break;
	case CMD_FRONT_IN:
		drive(FRONT_IN_DISTANCE);
		break;
	case CMD_BACK_AUTO_DRIVE:
		drive(-YELLOW_AUTO_DISTANCE);
		break;
	case CMD_ROTATE_90:
		rotate(90);
		break;
	case CMD_ROTATE_NEG_90:
		rotate(-90);
		break;
	case CMD_DRIVE_YELLOW_YELLOW:
		drive(YELLOW_YELLOW_DISTANCE);
		break;
	case CMD_BACK_TO_TOTE_DRIVE:
		drive(-BACK_TO_TOTE_DISTANCE);
		break;
	case CMD_DRIVE_YELLOW_CAN:
		drive(YELLOW_CAN_DISTANCE);
		break;
	case CMD_VISION_ROTATE_PLANAR:
		rotate(visPlanarAngle);
		break;
	case CMD_VISION_ROTATE_ROTATIONAL:
		rotate(visRotationalAngle);
		break;
	case CMD_VISION_DRIVE:
		drive(visDistance);
		break;
	default:
		// default states only occurs when illegal command is called
//		std::cout << "default command called in autoexec" << std::endl;
		break;
	}
}

// MACRO: picks up a tote, drives and drops it in the correct zone
void AutonomousExecutor::toteScore() {
	std::list<AutoCommand> toteScoreSet;
	toteScoreSet.push_back(CMD_TOTE_LIFT);
	toteScoreSet.push_back(CMD_AUTO_DRIVE);
	//toteScoreSet.push_back(CMD_DROP);
	//toteScoreSet.push_back(CMD_OPEN);

	comIt = commandSet->begin();
	advance(comIt, 1);
	commandSet->splice(comIt, toteScoreSet);
	commandSet->pop_front();
}

// MACRO: accumulates a gray tote from autonomous
void AutonomousExecutor::accumulateFromAuto() {

}

// MACRO: moves from one yellow tote to another with vision
void AutonomousExecutor::toteToTote(bool isLeft) {
	drive(YELLOW_YELLOW_DISTANCE);
}

// MACRO: picks up a can, drives and drops it in the correct zone
void AutonomousExecutor::canScore() {
	std::list<AutoCommand> canScoreSet;
	// fix me!!!!
	canScoreSet.push_back(CMD_TOTE_LIFT);
	canScoreSet.push_back(CMD_AUTO_DRIVE);
	canScoreSet.push_back(CMD_OPEN);

	comIt = commandSet->begin();
	advance(comIt, 2);
	commandSet->splice(comIt, canScoreSet);
	commandSet->pop_front();
}

// MACRO: moves from one gray tote to another
void AutonomousExecutor::grayToGray() {
	drive(GRAY_GRAY_DISTANCE);
}

// BASE_ARG: rotates a given angle
void AutonomousExecutor::rotate(int angle) {
	std::cout << "rotate method in AutoExecutor" << std::endl;
	robot->rotateAngle(angle);
}

// BASE: lifts a can
void AutonomousExecutor::canLift() {
	robot->liftCan();
}

// BASE_ARG: drives forward a set distance
void AutonomousExecutor::drive(int dist) {
	std::cout << "AutoExec::drive called" << std::endl;
	robot->driveDistance(dist);
}

// BASE: lifts a tote
void AutonomousExecutor::lift() {
	//Pid version
	cout << "Lifting arms" << endl;
	robot->liftDist(-LIFT_DISTANCE);
}

void AutonomousExecutor::lower() {
	robot->liftDist(LIFT_DISTANCE);
}

// BASE: drops whatever is being held
void AutonomousExecutor::drop() {
	robot->drop();
}

// BASE: opens the arms
void AutonomousExecutor::open() {
	cout << "Opening arms" << endl;
	robot->changePistonState(Arm::PistonState::EXTENDING);
}

// BASE: closes the arms
void AutonomousExecutor::close() {
	cout << "Closing arms" << endl;
	robot->changePistonState(Arm::PistonState::RETRACTING);
}

// MACRO: lifts a tote
void AutonomousExecutor::toteLift() {
	std::list<AutoCommand> toteLiftSet;
	cout << "Starting toteLift" << endl;
	toteLiftSet.push_back(CMD_CLOSE);
	toteLiftSet.push_back(CMD_LIFT);

	comIt = commandSet->begin();
	advance(comIt, 2);
	commandSet->splice(comIt, toteLiftSet);
	commandSet->pop_front();
}

// MACRO: Drops the held tote onto one below it and then picks up the stack
// Stack height is the lowest height to travel to
void AutonomousExecutor::toteStack(double stackHeight) {
	cout << "Stacking tote" << endl;
	std::list<AutoCommand> toteStackSet;
	//Only for chute door
//	toteStackSet.push_back(CMD_LIFT);
	toteStackSet.push_back(CMD_OPEN);
	//PID version
//	toteStackSet.push_back(CMD_DROP);
	//YOLO Swag limit switch version
	toteStackSet.push_back(CMD_LOWER);
//TODO: Want to lower arm to stackHeight....how?
	toteStackSet.push_back(CMD_TOTE_LIFT);

	comIt = commandSet->begin();
	advance(comIt, 2);
	commandSet->splice(comIt, toteStackSet);
	commandSet->pop_front();
	std::cout << "---------------------TOTE STACK DONE------------------" << std::endl;
	std::cout << "Current front: " << commandSet->front() << std::endl;
	std::cout << "Current back: " << commandSet->back() << std::endl;
}

void AutonomousExecutor::visionAccumulate() {
	std::list<AutoCommand> visionAccumulateSet;
	cout << "Starting visionAccumulate" << endl;
	visionAccumulateSet.push_back(CMD_VISION_ROTATE_PLANAR);
	visionAccumulateSet.push_back(CMD_VISION_DRIVE);
	visionAccumulateSet.push_back(CMD_VISION_ROTATE_ROTATIONAL);
	visionAccumulateSet.push_back(CMD_FRONT_IN);
	visionAccumulateSet.push_back(CMD_CLOSE);
	visionAccumulateSet.push_back(CMD_LIFT);

	// splicing untested with longer chains
	comIt = commandSet->begin();
	advance(comIt, 2);
	commandSet->splice(comIt, visionAccumulateSet);
	commandSet->pop_front();
}

/* checks if any of the subsystems are currently working
 * currently implemented: drivetrain and lifter
 */
bool AutonomousExecutor::isAllIdle() {
//	std::cout << "Arm state: " << robot->getArmPistonState() << std::endl;
	return (robot->getDrivetrainState() == Drivetrain::State::IDLE)
			&& (robot->getLifterState() == Lifter::State::IDLE)
			&& (robot->getArmPistonState() == Arm::PistonState::IDLE);
}

AutonomousExecutor::~AutonomousExecutor() {
	// TODO Auto-generated destructor stub
}

