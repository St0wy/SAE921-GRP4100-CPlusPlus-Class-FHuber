#pragma once
#include "Item.h"
class Weapon :
	public Item
{
protected:
	int damage_;
public:
	explicit Weapon(int damage);

	virtual void equip() = 0;
};

