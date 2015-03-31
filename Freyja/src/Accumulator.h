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
	enum class PistonState {
		EXTENDING, RETRACTING, SPINNING, IDLE
	}; PistonState pistonState;

	enum class WheelState {
		ACCUMULATING, EJECTING, SPINNING, IDLE
	}; WheelState wheelState;
	
	//Constructor and deconstructor
	Accumulator();
	virtual ~Accumulator();
	void setPistonState(PistonState state);
	void setWheelState(WheelState state);
	void eject();
	void init();
	void update();
	void disable();
	void accumulate();
	void togglePiston();
private:
	//solenoid for the pivoting action
	DoubleSolenoid solenoid;
	DoubleSolenoid solenoid2;
	double ejectSpeed;
	double vicSpeed;
	double leftSpinningSpeed;
	double rightSpinningSpeed;
	Timer timer;
	Victor leftVic;
	Victor rightVic;
	bool openPiston;
};

#endif /*ACCUMULATOR_H*/
