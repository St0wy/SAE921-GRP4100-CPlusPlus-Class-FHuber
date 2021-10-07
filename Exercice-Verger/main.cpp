#include "FruitTree.h"
#include <chrono>
#include <iostream>
#include <random>

using std::cout;
using std::endl;

constexpr int TREE_AMOUNT = 3;

int main()
{
	// obtain a seed from the system clock
	const uint32_t seed = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	std::default_random_engine gen(seed);

	std::vector<FruitTree> trees;

	trees.reserve(8);
	for (int i = 0; i < 2; ++i)
	{
		trees.emplace_back("Apple Tree", "Apple", gen, 150, 40, 50);
	}

	for (int i = 0; i < 3; ++i)
	{
		trees.emplace_back("Pear Tree", "Pear", gen, 90, 50, 70);
	}

	for (int i = 0; i < 3; ++i)
	{
		trees.emplace_back("Cherry Tree", "Cherry", gen, 5, 3000, 4000);
	}

	double total_weight = 0;

	for (int i = 0; i < 10; ++i)
	{
		cout << "The fruits grow...";
		double harvest_weight = 0;
		cout << "You got : " << endl;
		for (FruitTree tree : trees)
		{
			tree.grow_fruits();
			cout << tree.get_fruit_ammount() << " " << tree.get_fruit_name() << endl;
			harvest_weight += tree.get_total_weight();
		}

		total_weight += harvest_weight;

		cout << "This harvest you got " << harvest_weight / 1000.0 << " [kg] of fruits." << endl << endl;
	}

	cout << "During 10 harvests you got " << total_weight / 1000.0 << " [kg] of fruits." << endl;

	if (total_weight >= 200000)
	{
		cout << "Your contract is okay" << endl;
	}
	else
	{
		cout << "Your contract is over" << endl;
	}
}