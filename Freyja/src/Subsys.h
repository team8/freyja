//Subsystem Interface

#ifndef SRC_SUBSYS_H_
#define SRC_SUBSYS_H_

class Subsys {
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void disable() = 0;
	virtual ~Subsys() {};
};

#endif /* SRC_SUBSYS_H_ */
