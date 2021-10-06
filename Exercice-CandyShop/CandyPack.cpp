#include "CandyPack.h"

#include <iostream>

CandyPack::CandyPack()
	:candy_ammount_(0), candy_type_(CandyType::Jelly)
{
}

CandyPack::CandyPack(const CandyType candy_type)
	: candy_ammount_(0), candy_type_(candy_type)
{
}

bool CandyPack::buy_candies(const int ammount)
{
	if (candy_ammount_ >= ammount)
	{
		candy_ammount_ -= ammount;
		return true;
	}

	return false;
}

void CandyPack::print() const
{
	const std::string candy_type = get_candy_type_text(candy_type_);
	std::cout << "There are " << get_candy_ammount() << " candies in the " << candy_type << " pack" << std::endl;
}
