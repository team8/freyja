#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include <WPILib.h>
#include "Subsys.h"

/*
The accumulator is the arm like attachment at the base of the robot, which is
used to accumulate totes using spinning arms and a pneumatic pivot arm
*/

class Accumulator: public Subsys {
public:
	enum PistonState {
		EXTENDING, RETRACTING, IDLE
	}
	enum WheelState {
		IDLE, ACCUMULATING, EJECTING
	}
	
	//Constructor and deconstructor
	Accumulator();
	virtual ~Accumulator();
	//changes the state of the piston
	void setPistonState(PistonState state);
	//Subsystem inherited methods
	void eject();
	void setVictorSpeed(double speed);
	void init();
	void update();
	void disable();
private:
	//solenoid for the pivoting action
	DoubleSolenoid solenoid;
	PistonState pistonState;
	WheelState wheelState;
	double ejectSpeed;
	double vicSpeed;
	//victors/talons for the wheels
	Victor leftVic;
	Victor rightVic;
};

#endif /*ACCUMULATOR_H*/