#include "Plane.h"

#include <utility>

Plane::Plane()
	:Plane(0, "MISSINGNO", "MISSINGNAME")
{
}

Plane::Plane(const int motor_strength, std::string numberplate, std::string pilote_name)
	: FlyingVehicle(motor_strength, std::move(numberplate), std::move(pilote_name), 12490)
{
}
