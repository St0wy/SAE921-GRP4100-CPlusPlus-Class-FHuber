#include "CelestialBody.h"
#include "Ship.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	CelestialBody mercure("Mercure", 2439700.0 * 2.0, 60830000000.0, 69816900000.0, std::vector<AtmosphereElement>());

	const std::vector venus_elements{ AtmosphereElement::CarbonDioxide, AtmosphereElement::Diazote };
	CelestialBody venus("Venus", 6051800.0 * 2.0, 4.8675 * std::pow(10, 24) * 1000, 108943000000.0, venus_elements);
	Ship ship(mercure);

	cout << mercure << endl;
	cout << venus << endl << endl;

	cout << "The ship is currently on : " << endl;
	cout << ship.get_current_body() << endl;

	ship.travel(venus);

	cout << "The ship traveled to : " << endl;
	cout << ship.get_current_body() << endl;
}
void salut(int& a)
{
	int* a;
}