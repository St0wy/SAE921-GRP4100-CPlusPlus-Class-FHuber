#pragma once

enum class Planet
{
	Mars,
	Earth,
	SectorSD
};

const char* get_planet_text(Planet planet);