#include "Moon.h"

#include <utility>

Moon::Moon()
	:Moon("NO NAME", 0, 0, 0, std::vector<AtmosphereElement>())
{
}

Moon::Moon(std::string name, const double diameter, const double mass, const double distance_to_sun,
           std::vector<AtmosphereElement> atmosphere_elements)
	: CelestialBody(std::move(name), diameter, mass, distance_to_sun, std::move(atmosphere_elements))
{
}
