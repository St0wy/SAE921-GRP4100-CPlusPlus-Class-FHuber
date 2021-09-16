#include "Hero.h"

Hero::Hero(
	const double max_health,
	const double health,
	const std::default_random_engine& rnd_generator)
	:Entity(max_health,
		health,
		DEFAULT_DAMAGE,
		DEFAULT_DAMAGE,
		rnd_generator)
{
	protection_percentage_ = 0.0;
}

void Hero::defend()
{
	protection_percentage_ = DEFAULT_PROTECTION;
}

void Hero::heal()
{
	health_ += HEAL_AMMOUNT;
}

void Hero::remove_health(double damage)
{
	damage = damage * (1.0 - protection_percentage_);
	health_ -= damage;
}

void Hero::reset_buffs()
{
	protection_percentage_ = 0.0;
}
