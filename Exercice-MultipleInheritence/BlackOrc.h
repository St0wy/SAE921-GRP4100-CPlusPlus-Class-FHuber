#pragma once
#include "Orc.h"
#include "Warrior.h"

class BlackOrc final
	: public Orc, public Warrior
{
public:
	void hurt(Race& opponent) override;

	[[nodiscard]] double get_damage() const override;
};

