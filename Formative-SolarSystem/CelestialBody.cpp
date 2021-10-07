#include "CelestialBody.h"

#include <sstream>
#include <utility>

CelestialBody::CelestialBody()
	: CelestialBody("NONAME", 0, 0, 0, std::vector<AtmosphereElement>())
{
}

CelestialBody::CelestialBody(
	std::string name,
	const double diameter,
	const double mass,
	const double distance_to_sun,
	std::vector<AtmosphereElement> atmosphere_elements)
	: name_(std::move(name)),
	diameter_(diameter),
	mass_(mass),
	distance_to_sun_(distance_to_sun),
	atmosphere_elements_(std::move(atmosphere_elements))
{
}

const std::string& CelestialBody::get_name() const
{
	return name_;
}

double CelestialBody::get_diameter() const
{
	return diameter_;
}

double CelestialBody::get_mass() const
{
	return mass_;
}

double CelestialBody::get_distance_to_sun() const
{
	return distance_to_sun_;
}

const std::vector<AtmosphereElement>& CelestialBody::get_atmosphere_elements() const
{
	return atmosphere_elements_;
}

std::string CelestialBody::to_string() const
{
	std::ostringstream os;
	os << "The body \"" << name_ << "\" with a diameter of " << diameter_ << "[m] and a mass of "
	<< mass_ << "[kg] and a distance of " << distance_to_sun_ << "[m] to the sun.";
	return os.str();
}

std::ostream& operator<<(std::ostream& stream, const CelestialBody& body)
{
	stream << body.to_string();
	return stream;
}
