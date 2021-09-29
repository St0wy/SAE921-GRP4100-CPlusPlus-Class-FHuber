#pragma once
#include <array>
#include <random>

class Gun
{
public:
	// CONSTANTS
	static constexpr int BARREL_SIZE = 6;
	static constexpr int MIN_ROLL = 3;
	static constexpr int MAX_ROLL = 13;

private:
	std::array<bool, BARREL_SIZE> barrel_;
	std::default_random_engine gen_;
	std::size_t bullet_index_;

public:
	explicit Gun(const std::array<bool, BARREL_SIZE>& barrel, std::default_random_engine gen);

	/**
	 * \brief Rolls the barrel of the gun.
	 */
	void roll_barrel();

	/**
	 * \brief Shoots the bullet.
	 * \return True if a bullet was shot. False if there was no bullet.
	 */
	bool shoot();

	std::string get_barrel_text();

	void increment_bullet_index(int move_amount);
};

