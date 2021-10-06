#pragma once
#include "Vehicle.h"
class FlyingVehicle :
    public Vehicle
{
private:
    int altitude_;
public:
    FlyingVehicle();
    FlyingVehicle(int motor_strength, std::string numberplate, std::string pilote_name, int altitude);

    [[nodiscard]] int get_altitude() const;
};

