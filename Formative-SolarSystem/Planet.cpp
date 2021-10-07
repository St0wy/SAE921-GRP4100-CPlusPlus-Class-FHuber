#include "Planet.h"

#include <sstream>
#include <utility>

Planet::Planet()
	:CelestialBody(), moons_(std::vector<Moon>())
{
}

Planet::Planet(std::string name, const double diameter, const double mass, const double distance_to_sun,
               std::vector<AtmosphereElement> atmosphere_elements, std::vector<Moon> moons)
		:CelestialBody(std::move(name), diameter, mass, distance_to_sun, std::move(atmosphere_elements)), moons_(std::move(moons))
{
}

std::vector<Moon> Planet::get_moons() const
{
	return moons_;
}

std::string Planet::to_string() const
{
	std::ostringstream os;
	os << "The Planet \"" << get_name() << "\" with a diameter of " << get_diameter() << "[m] and a mass of "
		<< get_mass() << "[kg] and a distance of " << get_distance_to_sun() << "[m] to the sun.";
	return os.str();
}
