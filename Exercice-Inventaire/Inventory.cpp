#include "Inventory.h"

#include "Bow.h"
#include "Sword.h"
#include "Weapon.h"

#include <iostream>

Inventory::~Inventory()
{
	for (const auto item : items_)
	{
		delete item;
	}

	items_.clear();
}

void Inventory::add(Item* item)
{
	items_.emplace_back(item);
}

void Inventory::use(const int item_index)
{
	items_[item_index]->use();
}

void Inventory::equip_sword()
{
	for (const auto item : items_)
	{
		if (dynamic_cast<const Sword*>(item) != nullptr)
		{
			const auto sword = dynamic_cast<Sword*>(item);
			sword->equip();
			return;
		}
	}

	std::cout << "No sword found" << std::endl;
}

void Inventory::equip_bow()
{
	for (const auto item : items_)
	{
		if (dynamic_cast<const Bow*>(item) != nullptr)
		{
			const auto bow = dynamic_cast<Bow*>(item);
			bow->equip();
			return;
		}
	}

	std::cout << "No bow found" << std::endl;
}

void Inventory::remove(const int item_index)
{
	delete items_[item_index];
	items_.erase(items_.begin() + item_index);
}
