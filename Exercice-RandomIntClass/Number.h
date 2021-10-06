#pragma once
class Number
{
private:
	int number_{};
public:
	Number() = default;
	explicit Number(const int number) : number_(number) {}

	[[nodiscard]] int get_number() const { return number_; }
	void set_number(const int number) { number_ = number; }
};

