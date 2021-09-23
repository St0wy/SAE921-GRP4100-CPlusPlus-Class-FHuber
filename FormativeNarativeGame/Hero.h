#pragma once
#include <string>
#include <utility>
#include "Planet.h"
#include "Post.h"
#include "Race.h"
#include "lib.h"

class Hero
{
	std::string name_;
	std::string ship_name_;
	Planet planet_;
	std::tm birth_date_;
	Post post_;
	Race race_;
public:
	static constexpr const char* PREZ_HUMAN_STRING =
		"[name], Born on planet [planet] the [birthdate]. [role] of [shipname].";
	static constexpr const char* PREZ_METAMORPH_STRING =
		"[name], the metamorph. Created in [planet] the [birthdate]. [role] of [shipname]";

	Hero(std::string name,
		std::string ship_name,
		Planet planet,
		std::tm birth_date,
		Post post,
		Race race);

	[[nodiscard]] std::string to_string() const;
	[[nodiscard]] std::string get_name() const;
	[[nodiscard]] std::string get_ship_name() const;
	[[nodiscard]] Race get_race() const;
	[[nodiscard]] std::string get_birthdate_string() const;
	[[nodiscard]] Post get_post() const;
};

