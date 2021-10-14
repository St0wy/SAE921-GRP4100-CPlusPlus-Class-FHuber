#include "Bow.h"
#include "ForcePotion.h"
#include "HealthPotion.h"

#include <iostream>

#include "Inventory.h"
#include "Map.h"
#include "Sword.h"

using std::cout;
using std::endl;

int main()
{
	auto i = Inventory();
	i.add(new Map());
	i.add(new HealthPotion(5));
	i.add(new ForcePotion(10));
	i.add(new Sword(7));
	i.add(new Bow(7));

	cout << "Your inventory is full." << endl;

	cout << "You use the map." << endl;
	i.use(0);

	cout << endl << "You use the health potion." << endl;
	i.use(1);

	cout << endl << "You use the force potion." << endl;
	i.use(2);

	cout << endl << "You get rid of the map." << endl << endl;
	i.remove(0);

	cout << "You equip the sword." << endl;
	i.equip_sword();

	cout << endl << "You use the sword." << endl;
	i.use(2);

	cout << endl << "You equip the bow." << endl;
	i.equip_bow();

	cout << endl << "You use the bow." << endl;
	i.use(3);

	cout << endl << "You get rid of the sword." << endl;
	i.remove(2);

	cout << endl << "You equip the sword." << endl;
	i.equip_sword();

	cout << endl << "You get rid of the bow." << endl;
	i.remove(2);

	cout << endl << "You equip the bow." << endl;
	i.equip_bow();
}