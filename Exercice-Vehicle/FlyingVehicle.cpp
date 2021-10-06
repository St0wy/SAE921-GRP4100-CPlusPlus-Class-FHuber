#include "FlyingVehicle.h"

#include <utility>

FlyingVehicle::FlyingVehicle()
	: Vehicle(), altitude_(0)
{
}

FlyingVehicle::FlyingVehicle(const int motor_strength, std::string numberplate, std::string pilote_name, const int altitude)
	: Vehicle(motor_strength, std::move(numberplate), std::move(pilote_name)), altitude_(altitude)
{
}

int FlyingVehicle::get_altitude() const
{
	return altitude_;
}
