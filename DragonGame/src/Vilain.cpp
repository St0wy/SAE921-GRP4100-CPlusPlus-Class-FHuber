#include "Vilain.h"

Vilain::Vilain(
	const double max_health,
	const double health,
	const std::default_random_engine& rnd_generator)
	:Entity(max_health, health, DEFAULT_MIN_DAMAGE, DEFAULT_MAX_DAMAGE, rnd_generator)
{
	damage_modifier = 1.0;
}

void Vilain::invoque_waagh()
{
	damage_modifier = 2.0;
}

double Vilain::hit(Entity& enemy)
{
	const double damage = distribution_(rnd_generator_) * damage_modifier;
	enemy.remove_health(damage);
	return damage;
}
