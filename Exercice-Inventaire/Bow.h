#pragma once
#include "Weapon.h"
class Bow final :
    public Weapon
{
public:
	explicit Bow(int damage);

    void equip() override;
    void use() override;
};

