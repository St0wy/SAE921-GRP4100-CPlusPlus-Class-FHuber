#pragma once
#include <string>
#include <vector>

#include "AtmosphereElement.h"

class CelestialBody
{
private:
	std::string name_;

	/**
	 * \brief Diameter of the body in meters.
	 */
	double diameter_;


	/**
	 * \brief Mass of the body in kilogram.
	 */
	double mass_;

	/**
	 * \brief Distance of the body to the sun in meters.
	 */
	double distance_to_sun_;


	/**
	 * \brief Elements present in the atmosphere of this body.
	 */
	std::vector<AtmosphereElement> atmosphere_elements_;

public:
	CelestialBody();
	CelestialBody(
		std::string name,
		double diameter,
		double mass,
		double distance_to_sun,
		std::vector<AtmosphereElement> atmosphere_elements);

	[[nodiscard]] const std::string& get_name() const;
	[[nodiscard]] double get_diameter() const;
	[[nodiscard]] double get_mass() const;
	[[nodiscard]] double get_distance_to_sun() const;
	[[nodiscard]] const std::vector<AtmosphereElement>& get_atmosphere_elements() const;

	[[nodiscard]] virtual std::string to_string() const;

	friend std::ostream& operator<<(std::ostream& stream, const CelestialBody& body);
};

