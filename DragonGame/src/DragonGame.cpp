#include <iostream>
#include <chrono>
#include <locale>
#include "Entity.h"
#include "Hero.h"
#include "Vilain.h"
#include "GameState.h"

constexpr double THEOBALD_HEALTH = 50;
constexpr double GRIMGOR_HEALTH = 36;
constexpr int GIMGOR_WAAGH_CHANCE = 9;

bool prompt_for_char(const char* prompt, char& readch);
void handle_player_turn(Hero& theobald, Vilain& grimgor);
void hanle_vilain_turn(Hero& theobald, Vilain& grimgor, std::default_random_engine& generator);
void print_game_status(const Hero& theobald, const Vilain& grimgor);

int main()
{
	// obtain a seed from the system clock
	const uint32_t seed = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	// Create the rnd generator
	std::default_random_engine generator(seed);

	// Create theobald
	Hero theobald(THEOBALD_HEALTH, THEOBALD_HEALTH, generator);

	// Create Grimgor
	Vilain grimgor(GRIMGOR_HEALTH, GRIMGOR_HEALTH, generator);

	// Make the first state of the game to be the player turns
	auto game_state = GameState::PlayerTurn;

	std::cout << "Sir Theobald ! Vous affrontez l'orrible orgre noir Grimgor !" << std::endl;

	while (grimgor.get_health() > 0 && theobald.get_health() > 0)
	{
		switch (game_state)
		{
		case GameState::PlayerTurn:
			handle_player_turn(theobald, grimgor);
			game_state = GameState::VilainTurn;
			break;

		case GameState::VilainTurn:
			hanle_vilain_turn(theobald, grimgor, generator);
			game_state = GameState::PlayerTurn;
			break;
		}
	}

	if(grimgor.get_health() <= 0)
	{
		std::cout << "Vous avez gagne ! Bravo !" << std::endl;
	}

	if(theobald.get_health() <= 0)
	{
		std::cout << "Vous etes mort..." << std::endl;
	}
}

void hanle_vilain_turn(Hero& theobald, Vilain& grimgor, std::default_random_engine& generator)
{
	const auto distrib_waagh = std::uniform_int_distribution(0, GIMGOR_WAAGH_CHANCE);
	std::cout << "C'est le tour de Grimgor." << std::endl;

	if (distrib_waagh(generator) == 0)
	{
		std::cout << "Oh non ! Grimgor invoque la waagh !" << std::endl;
		grimgor.invoque_waagh();
	}

	const double damage = grimgor.hit(theobald);
	std::cout << "Grimgor a fait " << damage << " degats a theobald." << std::endl;
	print_game_status(theobald, grimgor);
}

void handle_player_turn(Hero& theobald, Vilain& grimgor)
{
	constexpr auto action_choice_text = "Que faites vous ?\na: Attaquer\nb: Se defendre\nc: Se soigner";
	char answer = 0;

	std::cout << "C'est votre tour, Theobald. " << std::endl;

	// Ask what the player wants to do
	while (prompt_for_char(action_choice_text, answer))
	{
		// Make the answer an lowercase char
		answer = tolower(answer, std::locale());
		if (answer == 'a')
		{
			const double damage = theobald.hit(grimgor);
			std::cout << "Theobald a fait " << damage << " degats a grimgor." << std::endl;
			break;
		}
		if (answer == 'b') {
			theobald.defend();
			break;
		}
		if (answer == 'c')
		{
			theobald.heal();
			std::cout << "Theobald se soigne de " << Hero::HEAL_AMMOUNT << " PV." << std::endl;
			break;
		}
	}

	print_game_status(theobald, grimgor);
}

void print_game_status(const Hero& theobald, const Vilain& grimgor)
{
	std::cout << "Theobald a " << theobald.get_health() <<
		"/" << theobald.get_max_health() << " PV." << std::endl;
	std::cout << "Grimgor a " << grimgor.get_health() <<
		"/" << grimgor.get_max_health() << " PV." << std::endl;
}

bool prompt_for_char(const char* prompt, char& readch)
{
	std::cout << prompt << std::endl;
	if (std::string tmp; std::getline(std::cin, tmp))
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