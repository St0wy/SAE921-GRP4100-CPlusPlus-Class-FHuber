#include <chrono>
#include <iostream>
#include <random>

constexpr int VEC_SIZE = 12;
constexpr int MIN_RND = 1;
constexpr int MAX_RND = 20;
constexpr int INSERT_VALUE = 0;

void print_vec(const std::vector<int>& numbers);
std::size_t find_smallest(const std::vector<int>& numbers);

int main()
{
	// obtain a seed from the system clock
	typedef std::chrono::high_resolution_clock myclock;
	const uint32_t seed = static_cast<uint32_t>(myclock::now().time_since_epoch().count());

	// Declare dice lambda (to get random numbers)
	std::default_random_engine generator(seed);
	const std::uniform_int_distribution<int> distribution(MIN_RND, MAX_RND);
	auto rnd = [&]() { return distribution(generator); };

	std::vector<int> numbers;

	// Take the memory that the vec will need
	numbers.reserve(VEC_SIZE);

	// Fill the vec
	for (int i = 0; i < VEC_SIZE; ++i)
	{
		numbers.push_back(rnd());
	}

	// Print vec
	std::cout << "The vec is : " << std::endl;
	print_vec(numbers);

	const std::size_t smallest_index = find_smallest(numbers);
	const int smallest = numbers[smallest_index];
	std::cout << "Smallest number is : " << smallest << std::endl;

	for (int i = 0; i < smallest; ++i)
	{
		numbers.insert(numbers.begin() + smallest_index + 1, INSERT_VALUE);
	}

	std::cout << "The new vec is : " << std::endl;
	print_vec(numbers);
}

void print_vec(const std::vector<int>& numbers)
{
	std::cout << "[";
	for (std::size_t i = 0; i < numbers.size(); i++)
	{
		if (i == (numbers.size() - 1))
		{
			std::cout << numbers[i];
		}
		else
		{
			std::cout << numbers[i] << ", ";
		}
	}

	std::cout << "]" << std::endl;
}


/**
 * \brief Finds the smallest number in the vector.
 * \param numbers Numbers to find the smallest in.
 * \return The index of the smallest number.
 */
std::size_t find_smallest(const std::vector<int>& numbers)
{
	std::size_t index = 0;
	int smallest = MAX_RND;
	for (std::size_t i = 0; i < numbers.size(); i++)
	{
		const int number = numbers[i];
		if(number < smallest)
		{
			smallest = number;
			index = i;
		}
	}

	return index;
}