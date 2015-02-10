#include "Lights.h"

Lights::Lights():

        setLightState(LIGHTSOFF);
        wiringPiSetup();
        for(int i = 0; i < 26; i ++){
                pinMode(i, OUTPUT);
        }
        }
Lights:~Lights(){
 //Empty Constructor
)

void Lights::setLightState(LightState state){
        this->lightState = state;
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
 case LIGHTSOFF:
 //Turns light off
 break;
 default:
 setLightState(DISABLED);
 //When we flat out break
 break;
 }

}
