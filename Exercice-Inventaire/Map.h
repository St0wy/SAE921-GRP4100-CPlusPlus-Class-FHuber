#pragma once
#include "Item.h"
class Map final :
    public Item
{
public:
    void use() override;
};

