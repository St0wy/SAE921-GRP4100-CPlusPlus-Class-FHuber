#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class NumberStorage
{
    // a collection of integers
	std::vector<int> numbers_;
    // Pointer to the mysterious function
    void (*callback_)(int) = nullptr;

public:
    // This method add a number into the vector then call the mysterious function
    void add(int number_to_add)
    {
        numbers_.emplace_back(number_to_add);
        callback_(numbers_.back());
    }

    // The function pointer is private, we need a method to connect
	void connect_callback(void(*function_to_call)(int))
    {
        callback_ = function_to_call;
    }

};

// Message to display into your function
constexpr char MESSAGE[] = "Int to display : ";

// The mysterious function
void callback_display(const int number_to_display)
{
    // Fill the function
    cout << MESSAGE << number_to_display << endl;
}

int main()
{
    NumberStorage my_number_storage;

    // Connect together callback(int) member
    my_number_storage.connect_callback(callback_display);

    // Add some number, each addtion should call callbackDisplay
    my_number_storage.add(6);
    my_number_storage.add(19);

}
