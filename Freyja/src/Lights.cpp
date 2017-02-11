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
                for(int i = PORT_ENABLED_START; i <= PORT_ENABLED_END; i ++){
                        digitalWrite(i, HIGH);
                }
                break;
                case DISABLED:
                for(int i = PORT_DISABLED_START; i < PORT_DISABLED_END; i ++){
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
                lightsOn = false;
                break;
                default:
                setLightState(DISABLED);
                //When we flat out break
                break;
                }
        }
void pwm(int pin, int angle){
        String cmd = "echo " +(std:string)pin = "=" + (std:string)angle + " > /dev/servoblaster"
}       //import os.system(cmd); //This sends the string to the system so the raspberry pi can run
        //whatever it does.
        //sleep(.5);
int Lights::main(){
        //Test Code
        digitalWrite(0, HIGH); 
        delay(10000);
        digitalWrite(0,  LOW);
        return 0;
        /*
        while(lightsOn){
        update();
        }
        return 0;
        */
}
