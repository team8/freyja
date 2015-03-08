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

AutonomousExecutor::AutonomousExecutor(Robot *robotPointer, std::list<AutoCommand> *commandSet) {
	this->robot = robotPointer;
	this->commandSet = commandSet;
}

void AutonomousExecutor::executeCommand(AutoCommand command) {
	std::cout << "AutonomousExecutor::executeCommand(" << command << ")"
			<< std::endl;
	switch(command) {
	case CMD_STOP:
	{
		break;
	}
	case CMD_AUTO_DRIVE:
	{
		//std::cout << "CMD_AUTO_DRIVE start" << std::endl;
		drive(YELLOW_AUTO_DISTANCE);
	//	std::cout << "CMD_AUTO_DRIVE end" << std::endl;
		break;
	}
	case CMD_LIFT:
	{
		lift();
		break;
	}
	case CMD_DROP:
	{
		drop();
		break;
	}
	case CMD_TOTE_SCORE:
	{
		toteScore();
		break;
	}
	case CMD_ACCUMULATE_FROM_AUTO:
	{
		accumulateFromAuto();
		break;
	}
	case CMD_TOTE_TO_TOTE_LEFT:
	{
		toteToTote(true);
		break;
	}
	case CMD_TOTE_TO_TOTE_RIGHT:
	{
		toteToTote(false);
		break;
	}
	case CMD_CAN_SCORE:
	{
		canScore();
		break;
	}
	case CMD_DRIVE_LANDFILL_AUTO:
	{
		drive(AUTO_GRAY_DISTANCE);
		break;
	}
	case CMD_GRAY_TO_GRAY:
	{
		grayToGray();
		break;
	}
	case CMD_HALF_ROTATE:
	{
		std::cout << "CMD_HALF_ROTATE start" << std::endl;
		rotate(180);
		std::cout << "CMD_HALF_ROTATE end" << std::endl;

		break;
	}
	case CMD_LANDFILL_DRIVE:
	{
		drive(YELLOW_AUTO_DISTANCE + AUTO_GRAY_DISTANCE);
		break;
	}
	case CMD_CAN_LIFT:
	{
		canLift();
		break;
	}
	case CMD_CLOSE:
	{
		close();
		break;
	}
	case CMD_OPEN:
	{
		open();
		break;
	}
	case CMD_TOTE_LIFT:
	{
		toteLift();
		break;
	}
	case CMD_VISION_ACCUMULATE:
	{
		visionAccumulate();
		break;
	}
	case CMD_BACK_OUT:
	{
		drive(-BACK_OUT_DISTANCE);
		break;
	}
	case CMD_FRONT_IN:
	{
		drive(FRONT_IN_DISTANCE);
		break;
	}
	case CMD_BACK_AUTO_DRIVE:
	{
		drive(-YELLOW_AUTO_DISTANCE);
		break;
	}
	case CMD_ROTATE_90:
	{
		rotate(90);
		break;
	}
	case CMD_ROTATE_NEG_90:
	{
		rotate(-90);
		break;
	}
	case CMD_DRIVE_YELLOW_YELLOW:
	{
		drive(YELLOW_YELLOW_DISTANCE);
		break;
	}
	case CMD_BACK_TO_TOTE_DRIVE:
	{
		drive(-BACK_TO_TOTE_DISTANCE);
		break;
	}
	case CMD_DRIVE_YELLOW_CAN:
	{
		drive(YELLOW_CAN_DISTANCE);
		break;
	}
	default:
	{
		// default states only occurs when illegal command is called
		std::cout << "default command called in autoexec" << std::endl;
		break;
	}
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

}

// MACRO: picks up a can, drives and drops it in the correct zone
void AutonomousExecutor::canScore() {
	std::list<AutoCommand> canScoreSet;
	// fix me!!!!
	canScoreSet.push_back(CMD_TOTE_LIFT);
	canScoreSet.push_back(CMD_AUTO_DRIVE);
	canScoreSet.push_back(CMD_OPEN);

	comIt = commandSet->begin();
	advance(comIt, 1);
	commandSet->splice(comIt, canScoreSet);
	commandSet->pop_front();
}

// MACRO: moves from one gray tote to another
void AutonomousExecutor::grayToGray() {

}

// BASE_ARG: rotates a given angle
void AutonomousExecutor::rotate(int angle) {
	std::cout << "rotate method in AutoExecutor" << std::endl;
	robot->rotateAngle(180);
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
	robot->liftDist(LIFT_DISTANCE);

}

// BASE: drops whatever is being held
void AutonomousExecutor::drop() {
	robot->drop();
}

// BASE: opens the arms
void AutonomousExecutor::open() {
	robot->changePistonState(Arm::PistonState::EXTENDING);
}

// BASE: closes the arms
void AutonomousExecutor::close() {
	robot->changePistonState(Arm::PistonState::RETRACTING);
}

// MACRO: lifts a tote
void AutonomousExecutor::toteLift() {
	std::list<AutoCommand> toteLiftSet;
	std::cout << "Starting toteLift" << std::endl;
	toteLiftSet.push_back(CMD_CLOSE);
	toteLiftSet.push_back(CMD_LIFT);

	comIt = commandSet->begin();
	advance(comIt, 1);
	commandSet->splice(comIt, toteLiftSet);
	commandSet->pop_front();
}

void AutonomousExecutor::visionAccumulate() {
	std::cout << "visionAccumulate called, shouldn't be called" << std::endl;
}

/* checks if any of the subsystems are currently working
 * currently implemented: drivetrain and lifter
 */
bool AutonomousExecutor::isAllIdle() {
	std::cout << "Drive state: " << robot->getDrivetrainState() << std::endl;
	std::cout << "Lifter state: " << robot->getLifterState() << std::endl;
	std::cout << "Arm state: " << robot->getArmPistonState() << std::endl;
	return (robot->getDrivetrainState() == Drivetrain::State::IDLE) &&
			(robot->getLifterState() == Lifter::State::IDLE) &&
					(robot->getArmPistonState() == Arm::PistonState::IDLE);
}

AutonomousExecutor::~AutonomousExecutor() {
	// TODO Auto-generated destructor stub
}

