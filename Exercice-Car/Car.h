#pragma once
#include <string>

class Car
{
	std::string brand_;
	std::string model_;
	std::string release_year_;
public:
	Car();
	Car(std::string brand, std::string model, std::string release_year);

	[[nodiscard]] std::string to_string() const;

	[[nodiscard]] std::string get_brand() const;
	[[nodiscard]] std::string get_model() const;
	[[nodiscard]] std::string get_release_year() const;
};

