#include "Helicopter.h"

Helicopter::Helicopter()
	:Helicopter(0, "MISSINGNO", "MISSINGNAME")
{
}

Helicopter::Helicopter(const int motor_strength, std::string numberplate, std::string pilote_name)
	: FlyingVehicle(motor_strength, std::move(numberplate), std::move(pilote_name), 10000)
{
}

std::string Helicopter::get_helmet_color()
{
	return helmet_color_;
}
