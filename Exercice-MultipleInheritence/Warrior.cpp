#include "Warrior.h"

Warrior::Warrior()
	:CombatClass()
{
}

double Warrior::get_damage() const
{
	return CombatClass::get_damage() * DAMAGE_BONUS;
}
