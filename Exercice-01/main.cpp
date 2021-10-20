#include <iostream>

using std::cout;
using std::endl;

int divide(const int a, const int b)
{
	return a / b;
}

float divide(const float a, const float b)
{
	return a / b;
}

int main()
{
	cout << "5 / 2 = " << divide(5, 2) << endl;
	cout << "5.0 / 2.0 = " << divide(5.0f, 2.0f) << endl;
}