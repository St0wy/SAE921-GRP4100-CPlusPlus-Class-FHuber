#pragma once
#include "Entity.h"
class Hero :
	public Entity
{
private:
	double protection_percentage_;
public:
	static constexpr int DEFAULT_DAMAGE = 5;
	static constexpr double DEFAULT_PROTECTION = 0.75;
	static constexpr int HEAL_AMMOUNT = 3;
	Hero(
		double max_health, 
		double health, 
		const std::default_random_engine& rnd_generator);
	void defend();
	void heal();
	void remove_health(double damage);
	void reset_buffs();
};

