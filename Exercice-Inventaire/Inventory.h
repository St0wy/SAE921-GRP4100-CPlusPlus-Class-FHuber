#pragma once
#include "Item.h"

#include <vector>

class Inventory
{
private:
	std::vector<Item*> items_;
public:
	Inventory() = default;
	~Inventory();
	Inventory(const Inventory& other) = default;
	Inventory(Inventory&&) = default;

	Inventory& operator=(const Inventory& other) = default;
	Inventory& operator=(Inventory&& other) noexcept = default;

	/**
	 * \brief Adds an item to the inventory.
	 * The inventory owns the item and is responsible to free the memory.
	 * \param item Item to add in the inventory.
	 */
	void add(Item* item);

	/**
	 * \brief Uses the selected item.
	 * \param item_index Index of the item to use.
	 */
	void use(int item_index);

	/**
	 * \brief Equips the first sword in the inventory.
	 */
	void equip_sword();

	/**
	 * \brief Equips the first bow in the inventory.
	 */
	void equip_bow();

	/**
	 * \brief Removes an item from the inventory. Frees the item from the memory.
	 * \param item_index Index of the item to remove.
	 */
	void remove(int item_index);
};

