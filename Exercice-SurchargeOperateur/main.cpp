#include "Point.h"
#include <iostream>

int main()
{
	const auto point = Point(10, 10);
	const auto point2 = Point(20, 25);
    std::cout << point + point2 << std::endl;
    std::cout << (point > point2 ? "True" : "False") << std::endl;
}