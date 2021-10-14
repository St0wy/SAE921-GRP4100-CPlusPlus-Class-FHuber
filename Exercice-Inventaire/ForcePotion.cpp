#include "ForcePotion.h"

#include <iostream>

ForcePotion::ForcePotion(const int force_buff)
	:force_buff_(force_buff)
{
}

void ForcePotion::use()
{
	std::cout << "You have been buffed with " << force_buff_ << " force." << std::endl;
}
