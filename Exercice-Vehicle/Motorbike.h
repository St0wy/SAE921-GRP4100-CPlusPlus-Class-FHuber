#pragma once
#include "IHelmet.h"
#include "WheelVehicle.h"
class Motorbike final :
    public WheelVehicle, public IHelmet
{
    Motorbike();
    Motorbike(int motor_strength, std::string numberplate, std::string pilote_name);
    std::string get_helmet_color() override;
};

