#include "Car.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	const auto mustang = Car("Ford", "Mustang", "1966");
	const auto panda = Car("Fiat", "Panda", "1982");

	cout << mustang.to_string() << endl << panda.to_string() << endl;
}