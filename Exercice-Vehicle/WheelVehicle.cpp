#include "WheelVehicle.h"

#include <utility>

WheelVehicle::WheelVehicle()
	:WheelVehicle(0, "MISSINGNO", "MISSINGNAME", 0)
{
}

WheelVehicle::WheelVehicle(
	const int motor_strength,
	std::string numberplate,
	std::string pilote_name,
	const int wheels_count)
	: Vehicle(motor_strength, std::move(numberplate), std::move(pilote_name)), wheels_count_(wheels_count)
{
}

int WheelVehicle::get_wheels_count() const
{
	return wheels_count_;
}
