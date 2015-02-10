#ifndef LIGHTS_H
#define LIGHTS_H

#include "Subsys.h"
#include <WPILIB.h>
#include <wiringPi.h>

class Lights{
public:
  enum LightState{
    ENABLED, DISABLED, TELEOPERATED, AUTONOMOUS,  LIGHTSOFF
  };
  Lights();
  virtual ~Lights();
  void setLightState();
  void update();
  int main();
private:
  LightState lightState;
};
  
  
#endif
