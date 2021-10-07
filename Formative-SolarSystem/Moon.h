#pragma once
#include "CelestialBody.h"

class Moon
	: public CelestialBody
{
public:
	Moon();
	Moon(std::string name,
		double diameter,
		double mass,
		double distance_to_sun,
		std::vector<AtmosphereElement> atmosphere_elements);
};

