#pragma once
#include "Race.h"

class CombatClass
{
private:
	double damage_;
public:
	static constexpr double DEFAULT_DAMAGE = 3;

	CombatClass();
	explicit CombatClass(double damage);

	[[nodiscard]] virtual double get_damage() const;

	virtual void hurt(Race& opponent);
};

