#include "Number.h"
#include "lib.h"

#include <iostream>
#include <chrono>
#include <random>
#include <vector>

using std::cout;
using std::endl;

constexpr int NUMBERS_QUANTITY = 15;

int main()
{
	// obtain a seed from the system clock
	const uint32_t seed = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	std::default_random_engine gen(seed);

	std::vector<Number> numbers;

	numbers.reserve(NUMBERS_QUANTITY);
	for (int i = 0; i < NUMBERS_QUANTITY; ++i)
	{
		const std::uniform_int_distribution<int> distrib;
		numbers.emplace_back(distrib(gen));
	}

	cout << "Initial List" << endl;
	print_numbers(numbers);

	remove_multiples(numbers, 3);

	cout << endl << "No multiples of 3" << endl;
	print_numbers(numbers);
}