#pragma once
#include "CombatClass.h"

class Archer :
    public CombatClass
{
private:
    int nb_arrows_;
public:
    static constexpr int DEFAULT_NB_ARROWS = 12;
    static constexpr int ARROWS_DAMAGE = 4;

    Archer();
    explicit Archer(int nb_arrows);

    [[nodiscard]] int get_nb_arrows() const;
    void shoot(Race& opponent);
};

