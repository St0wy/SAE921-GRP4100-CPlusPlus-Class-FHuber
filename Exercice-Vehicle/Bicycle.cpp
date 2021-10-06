#include "Bicycle.h"

Bicycle::Bicycle()
	: Bicycle(0, "MISSINGNO", "MISSINGNAME")
{
	
}

Bicycle::Bicycle(const int motor_strength, std::string numberplate, std::string pilote_name)
	: WheelVehicle(motor_strength, std::move(numberplate), std::move(pilote_name), 4)
{
}

std::string Bicycle::get_helmet_color()
{
	return IHelmet::helmet_color_;
}
