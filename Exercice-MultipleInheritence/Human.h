#pragma once
#include "Race.h"
class Human :
    public Race
{
public:
    static constexpr int DEFAULT_LIFEPOINTS = 35;
    static constexpr int HEAL_AMMOUNT = 10;

    Human();

    void prey();
};

