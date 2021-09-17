#pragma once
#include "Entity.h"
class Hero :
	public Entity
{
private:
	int protection_left;
public:
	static constexpr int DEFAULT_DAMAGE = 5;
	static constexpr double PROTECTION_PERCENTAGE = 0.75;
	static constexpr int HEAL_AMMOUNT = 5;
	static constexpr int DEFAULT_PROTECTION_DURATION = 3;
	Hero(
		double max_health, 
		double health, 
		std::default_random_engine& rnd_generator);
	void defend();
	void heal();
	void remove_health(double damage);
};

