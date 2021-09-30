#include <chrono>
#include <iostream>
#include <list>
#include <random>

constexpr int LIST_SIZE = 12;
constexpr int MIN_RND = 1;
constexpr int MAX_RND = 20;

void print_list(const std::list<int>& numbers);
void remove_even(std::list<int>& numbers);

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

	std::cout << "List without even numbers : " << std::endl;
	remove_even(numbers);
	print_list(numbers);
}

void remove_even(std::list<int>& numbers)
{
	//auto iter = numbers.begin();
	//const auto end = numbers.end();

	for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		if (*iter % 2 == 0)
		{
			iter = numbers.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	//while (iter != end)
	//{
	//if (*iter % 2 == 0)
	//{
	//	iter = numbers.erase(iter);
	//}
	//else
	//{
	//	++iter;
	//}
	//}
}

void print_list(const std::list<int>& numbers)
{
	for (const int number : numbers)
	{
		std::cout << number << std::endl;
	}
}