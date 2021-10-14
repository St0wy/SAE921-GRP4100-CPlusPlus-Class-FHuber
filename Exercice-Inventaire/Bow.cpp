#include "Bow.h"

#include <iostream>

Bow::Bow(const int damage) : Weapon(damage)
{
}

void Bow::equip()
{
	std::cout << "You have equiped the bow." << std::endl;
}

void Bow::use()
{
	std::cout << "You dealt " << damage_ << " damages with the bow." << std::endl;
}
