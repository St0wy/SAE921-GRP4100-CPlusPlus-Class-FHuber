#include <iostream>
#include <chrono>
#include <locale>
#include "Entity.h"
#include "Hero.h"
#include "Vilain.h"
#include "GameState.h"

constexpr double THEOBALD_HEALTH = 50;
constexpr double GRIMGOR_HEALTH = 20;

bool prompt_for_char(const char* prompt, char& readch);
void handle_player_turn(Hero& theobald, Vilain& grimgor);

int main()
{
	// obtain a seed from the system clock
	const uint32_t seed = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	// Create the rnd generator
	const std::default_random_engine generator(seed);

	// Create theobald
	Hero theobald(THEOBALD_HEALTH, THEOBALD_HEALTH, generator);

	// Create Grimgor
	Vilain grimgor(GRIMGOR_HEALTH, GRIMGOR_HEALTH, generator);

	// Make the first state of the game to be the player turns
	auto game_state = GameState::PlayerTurn;

	std::cout << "Sir Theobald ! Vous affrontez l'orrible orgre noir Grimgor !" << std::endl;

	while (grimgor.get_health() > 0)
	{
		switch (game_state)
		{
		case GameState::PlayerTurn:
			handle_player_turn(theobald, grimgor);
			break;

		case GameState::VilainTurn:
			// TODO: Handle vilain turn
			break;
		}
	}
}

void handle_player_turn(Hero& theobald, Vilain& grimgor)
{
	constexpr auto action_choice_text = "Que faites vous ?\na: Attaquer\nb: Se defendre\nc: Se soigner";
	char answer = 0;

	std::cout << "C'est votre tour, Theobald. " << std::endl;

	theobald.reset_buffs();

	// Ask what the player wants to do
	while (prompt_for_char(action_choice_text, answer))
	{
		// Make the answer an lowercase char
		answer = tolower(answer, std::locale());
		switch (answer)
		{
		case 'a':
			theobald.hit(grimgor);
			break;
		case 'b':
			theobald.defend();
			break;
		case 'c':
			theobald.heal();
			break;
		default:
			break;
		}
	}
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