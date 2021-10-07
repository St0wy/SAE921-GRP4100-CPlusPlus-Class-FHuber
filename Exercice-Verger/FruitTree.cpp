#include "FruitTree.h"

#include <utility>

FruitTree::FruitTree(std::default_random_engine& gen)
	: FruitTree("NONAME", "NONAME", gen, 0, 0, 0)
{
}

FruitTree::FruitTree(
	std::string tree_name,
	std::string fruit_name,
	std::default_random_engine& gen,
	const double fruit_weight,
	const int min_fruit_ammount,
	const int max_fruit_ammount)
	: tree_name_(std::move(tree_name)),
	fruit_name_(std::move(fruit_name)),
	gen_(gen),
	fruit_weight_(fruit_weight),
	min_fruit_ammount_(min_fruit_ammount),
	max_fruit_ammount_(max_fruit_ammount),
	fruit_ammount_(0)
{
}

void FruitTree::grow_fruits()
{
	const std::uniform_int_distribution distrib(min_fruit_ammount_, max_fruit_ammount_);
	fruit_ammount_ = distrib(gen_);
}

int FruitTree::get_fruit_ammount() const
{
	return fruit_ammount_;
}

double FruitTree::get_total_weight() const
{
	return fruit_weight_ * fruit_ammount_;
}

const std::string& FruitTree::get_tree_name() const
{
	return tree_name_;
}

const std::string& FruitTree::get_fruit_name() const
{
	return fruit_name_;
}
