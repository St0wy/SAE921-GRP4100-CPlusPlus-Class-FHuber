#include "Car.h"

#include <utility>

Car::Car()
	: Car(0, "MISSINGNO", "MISSINGNAME")
{
	
}

Car::Car(const int motor_strength, std::string numberplate, std::string pilote_name)
	: WheelVehicle(motor_strength, std::move(numberplate), std::move(pilote_name), 4)
{
}
