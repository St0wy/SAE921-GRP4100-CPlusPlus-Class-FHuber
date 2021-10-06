#include "CandyPack.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	auto chocolate_pack = CandyPack(CandyType::Chocolate);
	chocolate_pack.set_candy_ammount(6);
	auto lolipop_pack = CandyPack(CandyType::Lolipop);
	lolipop_pack.set_candy_ammount(20);
	cout << "I'll take you to the candy shop\n";
	chocolate_pack.print();
	lolipop_pack.print();
	cout << "You buy 6 lolipops..." << endl;
	if (lolipop_pack.buy_candies(6))
	{
		cout << "There where enough lolipop in the pack" << endl;
	}
	else
	{
		cout << "There wheren't enough lolipop in the pack" << endl;
	}
	lolipop_pack.print();

	cout << "You buy 7 chocolates..." << endl;
	if (chocolate_pack.buy_candies(7))
	{
		cout << "There where enough chocolate in the pack" << endl;
	}
	else
	{
		cout << "There wheren't enough chocolate in the pack" << endl;
	}
	chocolate_pack.print();
}