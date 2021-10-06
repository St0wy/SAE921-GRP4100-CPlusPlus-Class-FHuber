#pragma once
#include <string>

enum class CandyType
{
	Jelly,
	Caramel,
	Chocolate,
	Gummie,
	Lolipop
};

inline std::string get_candy_type_text(const CandyType candy_type)
{
	switch (candy_type) {
	case CandyType::Jelly:
		return "Jelly";
	case CandyType::Caramel:
		return "Caramel";
	case CandyType::Chocolate:
		return "Chocolate";
	case CandyType::Gummie:
		return "Gummie";
	case CandyType::Lolipop:
		return "Lolipop";
	}
	return "NO NAME";
}