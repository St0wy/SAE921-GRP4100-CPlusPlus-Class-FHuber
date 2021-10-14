#include "HealthPotion.h"

#include <iostream>

HealthPotion::HealthPotion(const int heal_ammount)
	:heal_ammount_(heal_ammount)
{
}

void HealthPotion::use()
{
	std::cout << "You have been healed " << heal_ammount_ << " PV." << std::endl;
}
