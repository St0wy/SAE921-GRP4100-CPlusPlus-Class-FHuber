#pragma once
#include "FlyingVehicle.h"
class Plane :
    public FlyingVehicle
{
public:
    Plane();
    Plane(int motor_strength, std::string numberplate, std::string pilote_name);
};

