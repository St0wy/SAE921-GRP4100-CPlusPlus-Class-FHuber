#pragma once
#include <random>

class Entity
{
protected:
	double max_health_;
	double health_;
	std::uniform_int_distribution<int> distribution_;
	std::default_random_engine rnd_generator_;

public:
	Entity(
		double max_health,
		double health,
		int min_damage,
		int max_damage,
		std::default_random_engine rnd_generator);
	double hit(Entity& enemy);
	void remove_health(double damage);
	[[nodiscard]] double get_max_health() const;
	[[nodiscard]] double get_health() const;
};

