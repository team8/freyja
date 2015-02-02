#ifndef ARM_H
#define ARM_H

#include <WPILib.h>
#include "Subsys.h"

class Arm: public Subsys {
public:
	enum CompressorState {
		ON, OFF
	};
	enum PistonState {
		EXTENDING, RETRACTING, IDLE, PUSH
	};

	Arm();
	virtual ~Arm();
	void setPistonState(PistonState state);
	void setCompressorState(CompressorState state);
	void init();
	void update();
	void disable();

private:
	Compressor compressor;
	DoubleSolenoid solenoid;

	CompressorState compressorState;
	PistonState pistonState;
};

#endif /* ARM_H */
