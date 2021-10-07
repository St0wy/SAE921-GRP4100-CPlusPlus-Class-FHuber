#pragma once
#include "Race.h"
class Orc :
	public Race
{
private:
	double damage_modifier_;
public:
	static constexpr int DEFAULT_LIFEPOINTS = 50;
	static constexpr double DEFAULT_DAMAGE_MODIFIER = 1;
	static constexpr double WAAGH_DAMAGE_MODIFIER = 1.5;

	Orc();
	explicit Orc(double damage_modifier);

	[[nodiscard]] double get_damage_modifier() const;
	void set_damage_modifier(double damage_modifier);

	void waagh();
};

