#pragma once
#include <string>

class Vehicle
{
private:
	int motor_strength_;
	std::string numberplate_;
	std::string pilote_name_;
public:
	Vehicle();
	Vehicle(int motor_strength, std::string numberplate, std::string pilote_name);

	[[nodiscard]] int get_motor_strength() const;
	[[nodiscard]] std::string numberplate() const;
	[[nodiscard]] std::string pilote_name() const;
};

