#ifndef ARM_H
#define ARM_H

#include <WPILib.h>
#include <iostream>

class Arm {
public:
	enum State {
		EXTENDING, RETRACTING, IDLE
	};

	Arm();

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
