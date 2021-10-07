#include "Orc.h"

Orc::Orc()
	: Orc(DEFAULT_DAMAGE_MODIFIER)
{
}

Orc::Orc(const double damage_modifier)
	: Race(DEFAULT_LIFEPOINTS), damage_modifier_(damage_modifier)
{
}

double Orc::get_damage_modifier() const
{
	return damage_modifier_;
}

void Orc::set_damage_modifier(const double damage_modifier)
{
	damage_modifier_ = damage_modifier;
}

void Orc::waagh()
{
	damage_modifier_ = WAAGH_DAMAGE_MODIFIER;
}
