#include "Point.h"

#include <iostream>

int main()
{
	const auto a = Point(1, 1);
	auto b = Point();

	std::cout << "Point A \n";
	a.print();

	b.input();

	std::cout << "Point B \n";
	b.print();

	std::cout << "Distance : " << a.distance(b) << std::endl;

	const Point center = a.center_point(b);
	std::cout << "Center : ";
	center.print();
}