#include <iostream>

using std::cout;
using std::endl;

void display(const int a)
{
	cout << a << endl;
}

int main()
{
	void (*display_ptr)(int) = display;
    display_ptr(5);
}