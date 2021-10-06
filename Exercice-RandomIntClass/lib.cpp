#include "lib.h"

#include <algorithm>
#include <iostream>

void print_numbers(const std::vector<Number>& numbers)
{
	for (const auto& number : numbers)
	{
		std::cout << number.get_number() << std::endl;
	}
}

void remove_multiples(std::vector<Number>& numbers, const int multiple)
{
	numbers.erase(std::ranges::remove_if(numbers, [&](const Number& number)
		{ return number.get_number() % multiple == 0; }).begin(), numbers.end());
}
