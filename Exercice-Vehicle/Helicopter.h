#pragma once
#include "FlyingVehicle.h"
#include "IHelmet.h"

class Helicopter final :
    public FlyingVehicle, public IHelmet
{
    public:
    Helicopter();
    Helicopter(int motor_strength, std::string numberplate, std::string pilote_name);
    std::string get_helmet_color() override;
};

