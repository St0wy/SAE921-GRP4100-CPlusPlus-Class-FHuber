#include <chrono>
#include <iostream>
#include <random>
#include <array>
#include <termcolor/termcolor.hpp>
#include "Gun.h"


int main()
{
	// obtain a seed from the system clock
	typedef std::chrono::high_resolution_clock myclock;
	const uint32_t seed = static_cast<uint32_t>(myclock::now().time_since_epoch().count());

	// Declare dice lambda (to get random numbers)
	std::default_random_engine generator(seed);
	const std::uniform_int_distribution<int> distrib(0, Gun::BARREL_SIZE - 1);

	// Je n'ai pas utilisé de vecteur comme on connait
	// la taille de notre tableau, ça ne faisait pas vraiment sens
	std::array<bool, Gun::BARREL_SIZE> barrel{};

	const int bullet_location = distrib(generator);
	barrel[bullet_location] = true;

	Gun gun(barrel, generator);

	std::cout << "Barrel content : " << gun.get_barrel_text() << std::endl;

	gun.roll_barrel();

	const bool was_shot_p1 = gun.shoot();
	const bool was_shot_p2 = gun.shoot();

	if (was_shot_p1)
	{
		std::cout << termcolor::red << "P1 was shot."
			<< std::endl << termcolor::reset;
	}
	else
	{
		std::cout << "P1 was NOT shot." << std::endl;
	}

	if (was_shot_p2)
	{
		std::cout << termcolor::red << "P2 was shot."
			<< std::endl << termcolor::reset;
	}
	else
	{
		std::cout << "P2 was NOT shot." << std::endl;
	}
}
