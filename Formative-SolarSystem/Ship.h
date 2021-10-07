#pragma once
#include "CelestialBody.h"

class Ship
{
private:
	CelestialBody current_body_;
public:
	explicit Ship(CelestialBody current_body);

	[[nodiscard]] const CelestialBody& get_current_body() const;

	void travel(CelestialBody destination);
};

