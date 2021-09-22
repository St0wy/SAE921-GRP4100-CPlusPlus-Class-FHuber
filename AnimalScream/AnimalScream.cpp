#include <iostream>
#include <string>
#include "ScreamType.h"

std::string get_scream(const ScreamType scream_type);

int main()
{
	constexpr ScreamType dog = ScreamType::Bark;
	constexpr ScreamType fish = ScreamType::Bubbles;
	constexpr ScreamType cat = ScreamType::Meowing;
	constexpr ScreamType lion = ScreamType::Roar;

	std::cout << get_scream(dog) << std::endl;
	std::cout << get_scream(fish) << std::endl;
	std::cout << get_scream(cat) << std::endl;
	std::cout << get_scream(lion) << std::endl;
}

std::string get_scream(const ScreamType scream_type)
{
	switch (scream_type)
	{
	case ScreamType::Bark:
		return "Woof woof";
	case ScreamType::Bubbles:
		return "Blub blub";
	case ScreamType::Meowing:
		return "Meow";
	case ScreamType::Roar:
		return "Rawr XD";
	}

	return "No scream";
}
