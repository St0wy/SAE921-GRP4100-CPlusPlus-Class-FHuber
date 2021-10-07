#pragma once

class Race
{
private:
	double life_points_;
public:
	Race();
	explicit Race(double life_points);
	virtual ~Race() = default;

	[[nodiscard]] double get_life_points() const;
	void set_life_points(double life_points);
	void recieve_damage(double damage);
};

