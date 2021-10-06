#include "Motorbike.h"

Motorbike::Motorbike()
	: Motorbike(0, "MISSINGNO", "MISSINGNAME")
{
}

Motorbike::Motorbike(const int motor_strength, std::string numberplate, std::string pilote_name)
	: WheelVehicle(motor_strength, std::move(numberplate), std::move(pilote_name), 4)
{
}

std::string Motorbike::get_helmet_color()
{
	return helmet_color_;
}
