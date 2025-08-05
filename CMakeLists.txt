cmake_minimum_required(VERSION 3.10)  # Versión mínima de CMake
project(raspi_temp_monitor)           # Nombre del proyecto

set(CMAKE_CXX_STANDARD 11)            # Usar C++11

find_library(PIGPIO_LIB pigpio)

if (NOT PIGPIO_LIB)
    message(FATAL_ERROR "pigpio no encontrado. Instálalo con: sudo apt-get install pigpio")
endif()

add_library(TemperatureController SHARED src/TemperatureController.cpp)
target_include_directories(TemperatureController PUBLIC include)

add_executable(temp_monitor src/main.cpp)
target_link_libraries(temp_monitor TemperatureController ${PIGPIO_LIB} )
