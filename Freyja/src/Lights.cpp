#include "Lights.h"

Lights::Lights():

        setLightState(ENABLED);
        }
Lights:~Lights(){
 //Empty Constructor
)

void Lights::setLightState(LightState state){
        this->lightState = state;
}
void init(){
 //Nothing necessary here, since we should start updating the lights immediately
 //
}
void Lights::update(){
 switch(lightState){
 case ENABLED:
 //Turns lights green
 break;
 case DISABLED:
 //Turns lights red
 break;
 case TELEOPERATED:
 //Does something else
 break;
 case AUTONOMOUS:
 //Does something else undecided
 break;
 default:
 setLightState(DISABLED);
 //When we flat out break
 break;
 }
 void Lights::disable(){
   //Flips lights off
 }
}
