#include <iostream>
#include <string>
#include "Hero.h"
#include "lib.h"
#include "Race.h"

constexpr const char* CHAPTER_1 =
"You landed on the planet [planet]. [shipname] is now dirty,"
" but you where able to fill the fuel tank.";
constexpr const char* CHAPTER_2 =
"You encounter a [npcRace]. \"Hello [race]. How are you ?\" You are not okay.";
constexpr const char* CHAPTER_3 =
"Your best friend [npcName] tells you \"Happy birthday !\"\n"
"They didn't know you where born on the [birthdate]. You are not okay.";
constexpr const char* CHAPTER_4 =
"Your ship doesn't let you in. \"But I am the [role] !\" you say, outside in the cold. You are not okay.";
constexpr const char* CHAPTER_5 =
"You're stuck on [stuckPlanet] on the [birthday]. Good luck.";

int main()
{
	std::tm tm_sarah{};
	tm_sarah.tm_mday = 24;
	tm_sarah.tm_mon = 7;
	tm_sarah.tm_year = 187;
	auto sarah = Hero("Sarah Shepard",
		"The Explorer",
		Planet::Earth,
		tm_sarah,
		Post::Captain,
		Race::Human);

	std::tm tm_phil{};
	tm_phil.tm_mday = 26;
	tm_phil.tm_mon = 7;
	tm_phil.tm_year = 138;
	auto phil = Hero("Phil Spector",
		"H-Hunter no3434-DFG",
		Planet::Mars,
		tm_phil,
		Post::Pilot,
		Race::Human);

	std::tm tm_whifghy{};
	tm_whifghy.tm_mday = 13;
	tm_whifghy.tm_mon = 5;
	tm_whifghy.tm_year = 108;
	auto whifghy = Hero("Whifghy",
		"The Bioship Sxiot",
		Planet::SectorSD,
		tm_whifghy,
		Post::Child,
		Race::Metamorph);

	std::cout << "Choose a hero : " << std::endl;
	std::cout << "1) " << sarah.to_string() << std::endl;
	std::cout << "2) " << phil.to_string() << std::endl;
	std::cout << "3) " << whifghy.to_string() << std::endl;

	char answer = 0;
	Hero& choosen_one = sarah;

	while (prompt_for_char("Lequel choisissez-vous ? [1-3]", answer))
	{
		// Make the answer an lowercase char
		if (answer == '1')
		{
			choosen_one = sarah;
			break;
		}
		if (answer == '2')
		{
			choosen_one = phil;
			break;
		}
		if (answer == '3')
		{
			choosen_one = whifghy;
			break;
		}
	}

	std::cout << "You choose " << choosen_one.get_name() << std::endl;

	std::string chapter_one = CHAPTER_1;
	find_n_replace(chapter_one, "[planet]", get_planet_text(Planet::Mars));
	find_n_replace(chapter_one, "[shipname]", choosen_one.get_ship_name());
	std::cout << std::endl << "Chapter One : " << std::endl << chapter_one << std::endl;

	std::string chapter_two = CHAPTER_2;
	find_n_replace(chapter_two, "[npcRace]", get_race_text(Race::Metamorph));
	find_n_replace(chapter_two, "[race]", get_race_text(choosen_one.get_race()));
	std::cout << std::endl << "Chapter Two : " << std::endl << chapter_two << std::endl;

	std::string chapter_three = CHAPTER_3;
	find_n_replace(chapter_three, "[npcName]", "Jean Guillaume");
	find_n_replace(chapter_three, "[birthdate]", choosen_one.get_birthdate_string());
	std::cout << std::endl << "Chapter Three : " << std::endl << chapter_three << std::endl;

	std::string chapter_four = CHAPTER_4;
	find_n_replace(chapter_four, "[role]", get_post_text(choosen_one.get_post()));
	std::cout << std::endl << "Chapter Four : " << std::endl << chapter_four << std::endl;

	std::string chapter_five = CHAPTER_5;
	find_n_replace(chapter_five, "[stuckPlanet]", get_planet_text(Planet::Mars));
	find_n_replace(chapter_five, "[birthday]", choosen_one.get_birthdate_string());
	std::cout << std::endl << "Chapter Five : " << std::endl << chapter_five << std::endl;
}

