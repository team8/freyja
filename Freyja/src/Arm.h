#ifndef ARM_H
#define ARM_H

#include <WPILib.h>
#include <iostream>

class Arm : public subsys{
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
