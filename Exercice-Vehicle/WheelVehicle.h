#pragma once
#include "Vehicle.h"
class WheelVehicle :
    public Vehicle
{
private:
    int wheels_count_;
public:
    WheelVehicle();
    WheelVehicle(int motor_strength, std::string numberplate, std::string pilote_name, int wheels_count);

    [[nodiscard]] int get_wheels_count() const;
};

