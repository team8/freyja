#ifndef ARM_H
#define ARM_H

#include <WPILib.h>
#include "Subsys.h"

class Arm : public Subsys {
public:
	enum CompressorState {
		ON, OFF
	};
	enum PistonState {
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

	CompressorState compressorState;
	PistonState pistonState;
};

#endif
