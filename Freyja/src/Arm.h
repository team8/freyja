#ifndef ARM_H
#define ARM_H

#include <iostream>
#include "Subsys.h"
#include <WPILib.h>

class Arm : public Subsys {
public:
	enum State {
		EXTENDING, RETRACTING, IDLE
	};

	Arm();
	virtual ~Arm();
	void setState(State state);
	void init();
	void update();
	void disable();

private:
	Compressor compressor;
	DoubleSolenoid solenoid;

	State state;
};

#endif
