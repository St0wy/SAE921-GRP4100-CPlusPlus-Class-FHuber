#include "Race.h"

Race::Race()
	: Race(0)
{
}

Race::Race(const double life_points)
	: life_points_(life_points)
{
}

double Race::get_life_points() const
{
	return life_points_;
}

void Race::set_life_points(const double life_points)
{
	life_points_ = life_points;
}

void Race::recieve_damage(const double damage)
{
	life_points_ -= damage;
}
