#include "CombatClass.h"

CombatClass::CombatClass()
	:CombatClass(DEFAULT_DAMAGE)
{
}

CombatClass::CombatClass(const double damage)
	: damage_(damage)
{
}

double CombatClass::get_damage() const
{
	return damage_;
}

void CombatClass::hurt(Race& opponent)
{
	opponent.recieve_damage(damage_);
}
