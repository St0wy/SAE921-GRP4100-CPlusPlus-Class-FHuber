#pragma once
#include "Entity.h"
class Vilain :
    public Entity
{
public:
    double damage_modifier;
    static constexpr int DEFAULT_MIN_DAMAGE = 2;
    static constexpr int DEFAULT_MAX_DAMAGE = 8;
    Vilain(
		double max_health, 
		double health, 
		const std::default_random_engine& rnd_generator);
    void invoque_waagh();
    double hit(Entity& enemy);
};

