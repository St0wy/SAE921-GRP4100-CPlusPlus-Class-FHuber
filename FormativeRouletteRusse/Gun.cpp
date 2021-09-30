#include "Gun.h"

Gun::Gun(const std::array<bool, BARREL_SIZE>& barrel, std::default_random_engine gen)
	:barrel_(barrel),
	gen_(gen),
	bullet_index_(0)
{}

void Gun::roll_barrel()
{
	const std::uniform_int_distribution<int> distrib(MIN_ROLL, MAX_ROLL);

	// Generate by how much the barrel will roll
	const int move_size = distrib(gen_);
	increment_bullet_index(move_size);
}

bool Gun::shoot()
{
	bool is_dead = false;
	if (barrel_[bullet_index_])
	{
		barrel_[bullet_index_] = false;
		is_dead = true;
	}

	increment_bullet_index(1);
	return is_dead;
}

std::string Gun::get_barrel_text()
{
	std::string text = "[";

	for (const bool is_bullet : barrel_)
	{
		text.append(is_bullet ? "true, " : "false, ");
	}

	text.append("]");

	return text;
}

void Gun::increment_bullet_index(const int move_amount)
{
	bullet_index_ += move_amount;
	bullet_index_ %= BARREL_SIZE;
}
