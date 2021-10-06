#include "Vehicle.h"

#include <utility>

Vehicle::Vehicle()
	:motor_strength_(0), numberplate_("MISSINGNO"), pilote_name_("MISSINGNAME")
{
}

Vehicle::Vehicle(const int motor_strength, std::string numberplate, std::string pilote_name)
	: motor_strength_(motor_strength), numberplate_(std::move(numberplate)), pilote_name_(std::move(pilote_name))
{
}

int Vehicle::get_motor_strength() const
{
	return motor_strength_;
}

std::string Vehicle::numberplate() const
{
	return numberplate_;
}

std::string Vehicle::pilote_name() const
{
	return pilote_name_;
}
