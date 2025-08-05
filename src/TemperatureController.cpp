#include "TemperatureController.hpp"
#include <fstream>


CTempController::CTempController(){

}

float CTempController::getCurrentCoreTemp() const {

    float result;
    std::ifstream temp_file(CORE_TEMP_FILE);

    if (!temp_file.is_open()) {
        //std::cerr << "Error al abrir el archivo de temperatura." << std::endl;
        return 1;
    }

    int temp_raw;
    temp_file >> temp_raw;  // Lee el valor en miligrados Celsius

    if (temp_file.fail()) {
        //std::cerr << "Error al leer la temperatura." << std::endl;
        return 1;
    }

    result = temp_raw / 1000.0f;

    return result;

}