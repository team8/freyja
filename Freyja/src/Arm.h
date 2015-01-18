#ifndef ARM_H
#define ARM_H

#include <WPILib.h>
#include <iostream>
#include "Subsys.h"

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
