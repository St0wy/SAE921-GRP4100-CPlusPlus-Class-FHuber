#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;

int main()
{
	// Some numbers
	std::vector numbers = { 12,54,42,42,56,78 };

	// Use what you learned fromm previous exercice
	// Use another lambda to substract and display into a for_each algorithm
	// Fill brackets with some code
	std::ranges::for_each(numbers, [](int& number)
	{
		number--;
		cout << "Number : " << number << endl;
	});
}