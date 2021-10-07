#pragma once
#include "CombatClass.h"

class Warrior :
    public CombatClass
{
public:
    static constexpr double DAMAGE_BONUS = 1.5;

    Warrior();

    [[nodiscard]] double get_damage() const override;
};

