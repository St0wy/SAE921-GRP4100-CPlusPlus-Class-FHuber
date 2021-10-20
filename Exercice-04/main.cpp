#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{

    // Some numbers
    const std::vector<int> numbers = { 12,54,42,42,56,78 };

    // Fill the  gaps in the lambda expression, display the value of an integer
    auto display = [](const int a) { cout << a << endl; };

    // Using the capture by reference :
    // Write a lambda expression substracting a parameter to a captured element into
    int capture = 1000000;
    auto substract = [&capture](const int a) { capture -= a; };

    // Use the lambda into the for loop below
    for (const auto number : numbers)
    {
        // Make the substract
        substract(number);

        // Display the result
        display(number);
        cout << "Capture : ";
        display(capture);
    }

    
}