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
 for(int i = 0; i < 9; i ++){
        digitalWrite(i, HIGH);
 }
 break;
 case DISABLED:
 for(int i = 9; i < 18; i ++){
        digitalWrite(i, LOW);
 }
 break;
 case AUTONOMOUS:
 //Does something else undecided
 break;
 case LIGHTSOFF:
 for(int i = 0; i < 26; i ++){
        digitalWrite(i, LOW);
 }
 break;
 default:
 setLightState(DISABLED);
 //When we flat out break
 break;
 }

}
int Lights::main(){
        //Test Code
        digitalWrite(0, HIGH); 
        delay(10000);
        digitalWrite(0,  LOW);
        return 0;
}
