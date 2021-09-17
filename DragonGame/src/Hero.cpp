#include <algorithm>
#include "Hero.h"

Hero::Hero(
	const double max_health,
	const double health,
	std::default_random_engine& rnd_generator)
	:Entity(max_health,
		health,
		DEFAULT_DAMAGE,
		DEFAULT_DAMAGE,
		rnd_generator)
{
	protection_left = 0;
}

void Hero::defend()
{
	protection_left = DEFAULT_PROTECTION_DURATION;
}

void Hero::heal()
{
	// Clamp to limit the HP to max health
	health_ = std::clamp(health_ + HEAL_AMMOUNT, 0.0, max_health_);
}

void Hero::remove_health(double damage)
{
	if(protection_left > 0)
	{
		damage = damage * (1.0 - PROTECTION_PERCENTAGE);
		protection_left -= 1;
	}
	Entity::remove_health(damage);
}
