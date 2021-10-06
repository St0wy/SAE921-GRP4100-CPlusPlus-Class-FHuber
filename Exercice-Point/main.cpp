#include "Point.h"

#include <iostream>

int main()
{
	const auto a = Point(1, 1);
	const auto b = Point(2, 2);

	std::cout << "Point A \n";
	a.print();

	std::cout << "Point B \n";
	b.print();

	std::cout << "Distance : " << a.distance(b) << std::endl;

	const Point center = a.center_point(b);
	std::cout << "Center : ";
	center.print();
}