#ifndef ARM_H
#define ARM_H

#include <WPILib.h>
#include "Subsys.h"
/*



The arm is a subsytem of the robot(and is also kind of a subsystem of the whole lifter mechanism). It is essentially
comprised of a solenoid, that controls the direction that the piston actuates, and a compressor, which gives the piston
air to actuate. The code for them is simple, since it's all direction based, and the compressor outputs a given number of psi
per second, thus, the code isn't too complex. The wrapper functions just check if the operatorJoystick button has been pressed,
and changes an enum based on that. (The compressor outputs .88 Cubic Feet Per Minute)

For more information, check the wiki, or consult the programmers referenced on the wiki.
*/



class Arm: public Subsys {
public:
	enum CompressorState {
		ON, OFF
	};
	enum PistonState {
		EXTENDING, RETRACTING, IDLE, PUSH
	};
	//Constructor and Deconstructor
	Arm();
	virtual ~Arm();
	//Enum changers which work with the update State Machine
	void setPistonState(PistonState state);
	void setCompressorState(CompressorState state);
	//Inherited Methods from subsystem:
	void init();
	void update();
	void disable();
	//
private:
	Compressor compressor;
	DoubleSolenoid solenoid;

	CompressorState compressorState;
	PistonState pistonState;
};

#endif /* ARM_H */
