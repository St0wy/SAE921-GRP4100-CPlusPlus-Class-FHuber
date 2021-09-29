#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, std::string> numbers;

	std::string firstname;
	std::string lastname;
	std::string phone_number;

	std::cout << "What is your firstname ?" << std::endl;
	std::getline(std::cin, firstname);
	std::cout << std::endl;

	std::cout << "What is your lastname ?" << std::endl;
	std::getline(std::cin, lastname);
	std::cout << std::endl;

	std::string fullname = firstname + " " + lastname;

	std::cout << "What is your phone number ?" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << std::endl;

	numbers.insert({ fullname, phone_number });
	numbers.insert({ "Jean Eude", "078 790 22 16" });
	numbers.insert({ "Mickey Mouse", "+41 666 42 00" });

	std::cout << "Here are all the numbers : " << std::endl;
	std::cout << "Number of " << fullname << " : " << numbers[fullname] << std::endl;
	std::cout << "Number of Jean Eude : " << numbers["Jean Eude"] << std::endl;
	std::cout << "Number of Mickey Mouse : " << numbers["Mickey Mouse"] << std::endl;
}