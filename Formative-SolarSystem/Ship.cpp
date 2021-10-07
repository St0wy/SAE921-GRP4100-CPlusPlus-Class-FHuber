#include "Ship.h"

#include <utility>

Ship::Ship(CelestialBody current_body)
	:current_body_(std::move(current_body))
{
}

const CelestialBody& Ship::get_current_body() const
{
	return current_body_;
}

void Ship::travel(CelestialBody destination)
{
	current_body_ = std::move(destination);
}
