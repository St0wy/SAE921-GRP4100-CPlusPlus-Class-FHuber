#pragma once
#include "CelestialBody.h"
#include "Moon.h"

class Planet :
	public CelestialBody
{
private:
	std::vector<Moon> moons_;
public:
	Planet();
	explicit Planet(
		std::string name,
		double diameter,
		double mass,
		double distance_to_sun,
		std::vector<AtmosphereElement> atmosphere_elements,
		std::vector<Moon> moons);

	[[nodiscard]] std::vector<Moon> get_moons() const;

	[[nodiscard]] std::string to_string() const override;
};

