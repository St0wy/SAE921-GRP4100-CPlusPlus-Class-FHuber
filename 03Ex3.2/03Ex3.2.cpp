#include <chrono>
#include <iostream>
#include <list>
#include <random>

constexpr int LIST_SIZE = 12;
constexpr int MIN_RND = 1;
constexpr int MAX_RND = 20;

void print_list(const std::list<int>& numbers);

int main()
{
	// obtain a seed from the system clock
	const uint32_t seed = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	// Declare dice lambda (to get random numbers)
	std::default_random_engine gen(seed);
	const std::uniform_int_distribution<int> distrib(MIN_RND, MAX_RND);
	std::list<int> numbers;

	for (int i = 0; i < LIST_SIZE; ++i)
	{
		numbers.push_back(distrib(gen));
	}

	std::cout << "First list : " << std::endl;
	print_list(numbers);
	std::cout << std::endl;

	numbers.erase(std::prev(numbers.end(), 3), numbers.end());
	std::cout << "Modified list : " << std::endl;
	print_list(numbers);
}

void print_list(const std::list<int>& numbers)
{
	for (const int number : numbers)
	{
		std::cout << number << std::endl;
	}
}