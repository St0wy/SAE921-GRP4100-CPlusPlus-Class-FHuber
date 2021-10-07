#include "BlackOrc.h"

void BlackOrc::hurt(Race& opponent)
{
	opponent.recieve_damage(get_damage());
	set_damage_modifier(1);
}

double BlackOrc::get_damage() const
{
	return Warrior::get_damage() * get_damage_modifier();
}
