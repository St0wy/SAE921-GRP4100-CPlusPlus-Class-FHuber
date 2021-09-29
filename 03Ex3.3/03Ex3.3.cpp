#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

constexpr std::size_t MIN_WORD_LENGTH = 5;

void remove_short_words(std::vector<std::string>& text);
std::vector<std::string> split(const std::string& s, const char delimiter);

int main()
{
	const std::string text = "Sometimes ideas are like good wine in that they just need time";

	std::cout << text << std::endl;

	// Split on spaces
	std::vector<std::string> splitted_text = split(text, ' ');

	remove_short_words(splitted_text);

	for (const std::string& word : splitted_text)
	{
		std::cout << word << " ";
	}
}

void remove_short_words(std::vector<std::string>& text)
{
	auto is_too_small = [](const std::string& word)
	{
		return word.size() < MIN_WORD_LENGTH;
	};

	text.erase(
		std::ranges::remove_if(text, is_too_small).begin(), text.end());
}

std::vector<std::string> split(const std::string& s, const char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream token_stream(s);
	while (std::getline(token_stream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}