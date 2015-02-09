#ifndef LIGHTS_H
#define LIGHTS_H

#include "Subsys.h"
#include <WPILIB.h>
#include <wiringPi.h>

class Lights:public Subsys{
public:
  enum LightState{
    ENABLED, DISABLED, TELEOPERATED, AUTONOMOUS
  };
  Lights();
  virtual ~Lights();
  void setLightState();
  void init();
  void update();
  void disable(); 
private:
  LightState lightState;
};
  
  
#endif
