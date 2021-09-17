#pragma once
#include "Entity.h"
class Vilain :
    public Entity
{
    double damage_modifier_;
public:
    static constexpr int DEFAULT_MIN_DAMAGE = 2;
    static constexpr int DEFAULT_MAX_DAMAGE = 8;
    Vilain(
		double max_health, 
		double health, 
        std::default_random_engine& rnd_generator);
    void invoque_waagh();
    double hit(Entity& enemy) const;
    [[nodiscard]] bool has_waagh() const;
};

