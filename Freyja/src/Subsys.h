//Subsystem Interface

#ifndef SUBSYS_H
#define SUBSYS_H


class Subsys {
public:
	virtual void init() = 0;
	virtual void TeleopUpdate() = 0;
	virtual void AutonomousUpdate() = 0;
	virtual void disable() = 0;
	virtual ~Subsys() {};
};

#endif /* SUBSYS_H */
