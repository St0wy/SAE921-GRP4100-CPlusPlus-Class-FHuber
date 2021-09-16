#include <iostream>
#include <random>
#include <string>
#include <cctype>
#include <locale>
#include <chrono>

constexpr int min_score = 7;

bool prompt_for_char(const char* prompt, char& readch);

int main()
{
	// obtain a seed from the system clock
	typedef std::chrono::high_resolution_clock myclock;
	const uint32_t seed = static_cast<uint32_t>(myclock::now().time_since_epoch().count());

	// Declare dice lambda (to get random numbers)
	std::default_random_engine generator(seed);
	const std::uniform_int_distribution<int> distribution(1, 6);
	auto roll = [&]() { return distribution(generator); };

	// Game variables
	int moneyP1 = 0;
	int moneyP2 = 0;
	int score = 0;
	bool is_keeping_gain = false;
	char answer = 0;

	// Get the initial bet
	do
	{
		std::cout << "Give an inital bet : " << std::endl;
		std::cin >> money;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (money <= 0);

	// Main game loop
	while (!is_keeping_gain)
	{
		// Roll the dice
		score = roll() + roll();
		std::cout << "The dice rolled : " << score << std::endl;

		if (score <= min_score)
		{
			// The money is lost
			std::cout << "You lost " << money << " DOLLARS" << std::endl;
			break;
		}

		// The money is doubled
		money *= 2;
		std::cout << "You now have " << money << " DOLLARS" << std::endl;

		// Ask if the player wants to bet again
		while (prompt_for_char("Do you wanna bet again ? [Y/n]", answer))
		{
			// Make the answer an lowercase char
			answer = tolower(answer, std::locale());
			if (answer == 'y')
			{
				// The user wants to play, break the while of the prompt
				break;
			}

			if (answer == 'n')
			{
				// The user leaves, break and set the bool for the main loop
				std::cout << "You leave with : " << money << std::endl;
				is_keeping_gain = true;
				break;
			}
		}
	}

}

bool prompt_for_char(const char* prompt, char& readch)
{
	std::string tmp;
	std::cout << prompt << std::endl;
	if (std::getline(std::cin, tmp))
	{
		// Only accept single character input
		if (tmp.length() >= 1)
		{
			readch = tmp[0];
		}
		else
		{
			// For most input, char zero is an appropriate sentinel
			readch = '\0';
		}
		return true;
	}
	return false;
}