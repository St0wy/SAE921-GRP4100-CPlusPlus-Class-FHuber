#pragma once
#include "WheelVehicle.h"
class Car final :
    public WheelVehicle
{
public:
    Car();
    Car(int motor_strength, std::string numberplate, std::string pilote_name);
};

