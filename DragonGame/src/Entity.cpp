#include "Entity.h"

Entity::Entity(
	const double max_health,
	const double health,
	const int min_damage,
	const int max_damage,
	const std::default_random_engine rnd_generator)
	: max_health_(max_health),
	health_(health),
	rnd_generator_(rnd_generator)
{
	distribution_ = std::uniform_int_distribution<int>(min_damage, max_damage);
}

void Entity::remove_health(const double damage)
{
	health_ -= damage;
}

double Entity::get_max_health() const
{
	return max_health_;
}

double Entity::get_health() const
{
	return health_;
}

double Entity::hit(Entity& enemy)
{
	const double damage = distribution_(rnd_generator_);
	enemy.remove_health(damage);
	return damage;
}
