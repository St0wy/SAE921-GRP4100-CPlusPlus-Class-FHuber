#pragma once
#include "Weapon.h"
class Sword final :
    public Weapon
{
public:
	explicit Sword(int damage);

    void equip() override;
    void use() override;
};

