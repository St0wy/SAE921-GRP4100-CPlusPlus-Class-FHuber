#include <iostream>

#include "BlackOrc.h"
#include "HumanArcher.h"

using std::cout;
using std::endl;

void print_info(const BlackOrc& grimgor, const HumanArcher& robin_hood);

int main()
{
	BlackOrc grimgor;
	HumanArcher robin_hood;

	cout << "Grimgor VS Robin Hood" << endl;

	print_info(grimgor, robin_hood);

	robin_hood.shoot(grimgor);
	cout << "Robin hood shoots Grimgor" << endl;
	print_info(grimgor, robin_hood);

	grimgor.hurt(robin_hood);
	cout << "Grimgor hurts robin hood" << endl;
	print_info(grimgor, robin_hood);

	robin_hood.hurt(grimgor);
	cout << "robin hood hurts Grimgor" << endl;
	print_info(grimgor, robin_hood);

	grimgor.waagh();
	cout << "Grimgor invoques the waagh" << endl;
	print_info(grimgor, robin_hood);

	robin_hood.prey();
	cout << "Robin Hood prays" << endl;
	print_info(grimgor, robin_hood);

	grimgor.hurt(robin_hood);
	cout << "Grimgor hurts robin hood" << endl;
	print_info(grimgor, robin_hood);
}

void print_info(const BlackOrc& grimgor, const HumanArcher& robin_hood)
{
	cout << "Grimgor : " << grimgor.get_life_points() << " PV, " << grimgor.get_damage() << " damage." << endl;
	cout << "Robin Hood : " << robin_hood.get_life_points() << " PV, " << robin_hood.get_damage() << " damage " << robin_hood.get_nb_arrows() << " arrows." << endl << endl;
}