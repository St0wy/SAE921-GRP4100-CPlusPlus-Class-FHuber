#include "Race.h"

const char* get_race_text(const Race planet)
{
	switch (planet) {
	case Race::Human:
		return "Human";
	case Race::Metamorph:
		return "Metamorph";
	}

	return "NO NAME";
}
