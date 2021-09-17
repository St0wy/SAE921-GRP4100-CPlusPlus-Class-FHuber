#include "Vilain.h"

Vilain::Vilain(
	const double max_health,
	const double health,
	std::default_random_engine& rnd_generator)
	:Entity(max_health, health, DEFAULT_MIN_DAMAGE, DEFAULT_MAX_DAMAGE, rnd_generator)
{
	damage_modifier_ = 1.0;
}

void Vilain::invoque_waagh()
{
	damage_modifier_ = 2.0;
}

double Vilain::hit(Entity& enemy) const
{
	const double damage = distribution_(rnd_generator_) * damage_modifier_;
	enemy.remove_health(damage);
	return damage;
}

bool Vilain::has_waagh() const
{
	return damage_modifier_ > 1.0;
}
