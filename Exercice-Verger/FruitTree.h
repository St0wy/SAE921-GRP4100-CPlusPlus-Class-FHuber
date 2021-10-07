#pragma once
#include <random>
#include <string>

class FruitTree
{
private:
	std::string tree_name_;
	std::string fruit_name_;
	std::default_random_engine& gen_;
	double fruit_weight_;
	int min_fruit_ammount_;
	int max_fruit_ammount_;
	int fruit_ammount_;
public:
	explicit FruitTree(std::default_random_engine& gen);
	FruitTree(
		std::string tree_name,
		std::string fruit_name,
		std::default_random_engine& gen,
		double fruit_weight,
		int min_fruit_ammount,
		int max_fruit_ammount);

	void grow_fruits();
	[[nodiscard]] int get_fruit_ammount() const;
	[[nodiscard]] double get_total_weight() const;
	[[nodiscard]] const std::string& get_tree_name() const;
	[[nodiscard]] const std::string& get_fruit_name() const;
};

