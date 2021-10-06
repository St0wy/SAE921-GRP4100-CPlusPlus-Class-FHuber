#pragma once
#include "IHelmet.h"
#include "WheelVehicle.h"
class Bicycle final :
    public WheelVehicle, public IHelmet
{
    Bicycle();
    Bicycle(int motor_strength, std::string numberplate, std::string pilote_name);
    std::string get_helmet_color() override;
};

