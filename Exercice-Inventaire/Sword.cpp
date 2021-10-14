#include "Sword.h"

#include <iostream>

Sword::Sword(const int damage) : Weapon(damage)
{
}

void Sword::equip()
{
	std::cout << "You have equiped the sword." << std::endl;
}

void Sword::use()
{
	std::cout << "You dealt " << damage_ << " damages with the sword." << std::endl;
}
