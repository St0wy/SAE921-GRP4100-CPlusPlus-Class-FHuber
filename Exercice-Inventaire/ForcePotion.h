#pragma once
#include "Potion.h"
class ForcePotion final :
    public Potion
{
private:
    int force_buff_;
public:
    explicit ForcePotion(int force_buff);

    void use() override;
};

