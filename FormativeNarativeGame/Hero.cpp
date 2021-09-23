#include "Hero.h"

Hero::Hero(
	std::string name,
	std::string ship_name,
	const Planet planet,
	const std::tm birth_date,
	const Post post,
	const Race race)
	: name_(std::move(name)),
	ship_name_(std::move(ship_name)),
	planet_(planet),
	birth_date_(birth_date),
	post_(post),
	race_(race)
{
}

std::string Hero::to_string() const
{
	std::string prez_string;
	switch (race_) {
	case Race::Human:
		prez_string = PREZ_HUMAN_STRING;
		break;
	case Race::Metamorph:
		prez_string = PREZ_METAMORPH_STRING;
		break;
	}

	find_n_replace(prez_string, "[name]", name_);
	find_n_replace(prez_string, "[planet]", get_planet_text(planet_));
	find_n_replace(prez_string, "[birthdate]", get_birthdate_string());
	find_n_replace(prez_string, "[role]", get_post_text(post_));
	find_n_replace(prez_string, "[shipname]", ship_name_);

	return prez_string;
}

std::string Hero::get_name() const
{
	return name_;
}

std::string Hero::get_ship_name() const
{
	return ship_name_;
}

Race Hero::get_race() const
{
	return race_;
}

std::string Hero::get_birthdate_string() const
{
	return std::to_string(birth_date_.tm_mday) + "/"
		+ std::to_string(birth_date_.tm_mon) + "/"
		+ std::to_string(birth_date_.tm_year + 1900);
}

Post Hero::get_post() const
{
	return post_;
}
