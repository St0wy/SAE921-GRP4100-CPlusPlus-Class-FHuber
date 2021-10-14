#pragma once
#include "Potion.h"
class HealthPotion final :
    public Potion
{
private:
    int heal_ammount_;
public:
    explicit HealthPotion(int heal_ammount);

    void use() override;
};

