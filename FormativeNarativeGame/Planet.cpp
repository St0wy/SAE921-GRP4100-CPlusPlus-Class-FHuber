#include "Planet.h"

const char* get_planet_text(const Planet planet)
{
	switch (planet) {
	case Planet::Mars:
		return "Mars";
	case Planet::Earth:
		return "Earth";
	case Planet::SectorSD:
		return "Sector SD/F67";
	}

	return "NO NAME";
}