#include <iostream>
#include <exception>
#include <chrono>
#include <random>

constexpr int MIN = 0;
constexpr int MAX = 20;
constexpr int ARRAY_SIZE = 10;

void array_init(
	int array[], 
	int length, 
	std::default_random_engine generator,
	std::uniform_int_distribution<int> distrib);

bool is_in_array(const int num, int array[], const int length);

int main()
{
	// obtain a seed from the system clock
	typedef std::chrono::high_resolution_clock myclock;
	const uint32_t seed = static_cast<uint32_t>(myclock::now().time_since_epoch().count());

	// Declare number generator and distribution
	const std::default_random_engine generator(seed);
	const std::uniform_int_distribution<int> distribution(MIN, MAX);

	// User input
	int input_number = 0;
	int array[ARRAY_SIZE];
	array_init(array, ARRAY_SIZE, generator, distribution);

	std::cout << "Please input a number to find in the array ["
		<< MIN << "-" << MAX << "] : " << std::endl;
	std::cin >> input_number;

	if (input_number <= MIN || input_number > MAX)
	{
		throw std::exception("Input number out of bounds.");
	}

	if(is_in_array(input_number, array, ARRAY_SIZE))
	{
		std::cout << input_number << " is in the array." << std::endl;
	} else
	{
		std::cout << input_number << " is NOT in the array." << std::endl;
	}
}

void array_init(
	int array[],
	const int length, 
	std::default_random_engine generator,
	const std::uniform_int_distribution<int> distrib)
{
	for (int i = 0; i < length; ++i)
	{
		array[i] = distrib(generator);
	}
}

bool is_in_array(const int num, int array[], const int length)
{
	for (int i = 0; i < length; ++i)
	{
		if(array[i] == num)
		{
			return true;
		}
	}
	return false;
}