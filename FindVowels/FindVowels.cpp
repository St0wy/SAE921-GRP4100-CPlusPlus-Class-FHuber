#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

bool is_vowel(char c);
int get_vowels_number(const std::string& str);

int main()
{
	std::string user_string;
	std::cout << "Please input some text, i'll cound the vowels : " << std::endl;
	std::getline(std::cin, user_string);

	const int vowels_number = get_vowels_number(user_string);

	std::cout << "There are " << vowels_number << " vowels.";
}

int get_vowels_number(const std::string& str)
{
	int vowels_number = 0;
	for (const auto c : str)
	{
		if (is_vowel(c))
		{
			vowels_number++;
		}
	}

	return vowels_number;
}

bool is_vowel(char c)
{
	constexpr char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };

	return std::any_of(
		std::begin(vowels),
		std::end(vowels),
		[c](const char vowel)
		{
			return vowel == tolower(c, std::locale());
		});
}

