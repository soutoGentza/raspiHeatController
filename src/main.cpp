#include <pigpio.h>
#include <iostream>
#include <unistd.h>
#include "TemperatureController.hpp"


#define FAN_SWITCH_PIN 17

const float MAX_TEMP_THRESHOLD = 50.0;

bool gpioSetUp();
void activateFan();
void deactivateFan();

int main(){

    if( !gpioSetUp()){
        return 1;
    }

    CTempController tempController;
    float currentTemp = 0.0;

        // Encender y apagar el LED
    while (true) {

        currentTemp = tempController.getCurrentCoreTemp();

        std::cout<<"Temperatura actual "<<currentTemp<<std::endl;

        if(currentTemp > MAX_TEMP_THRESHOLD){

            activateFan();

        }else{

            deactivateFan();

        }        

        sleep(1);
    }

}


bool gpioSetUp(){
    // Inicializar pigpio
    if (gpioInitialise() < 0) {
        std::cerr << "Error al inicializar pigpio." << std::endl;
        return false;
    }

    // Configurar el pin como salida
    gpioSetMode(FAN_SWITCH_PIN, PI_OUTPUT);
    return true;
}

void activateFan(){
        gpioWrite(FAN_SWITCH_PIN, 1);  // Encender
        std::cout << "LED ENCENDIDO" << std::endl;
}


void deactivateFan(){

    gpioWrite(FAN_SWITCH_PIN, 0);  // Apagar
    std::cout << "LED APAGADO" << std::endl;

}
