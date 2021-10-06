#pragma once
#include "CandyType.h"

class CandyPack
{
private:
	int candy_ammount_;
	CandyType candy_type_;
public:
	CandyPack();
	explicit CandyPack(CandyType candy_type);

	[[nodiscard]] int get_candy_ammount() const { return candy_ammount_; }
	void set_candy_ammount(const int candy_ammount) { candy_ammount_ = candy_ammount; }

	bool buy_candies(int ammount);
	void print() const;
};

