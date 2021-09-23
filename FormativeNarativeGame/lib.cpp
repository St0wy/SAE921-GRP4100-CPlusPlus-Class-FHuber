#include "lib.h"

void find_n_replace(
	std::string& text,
	const std::string& to_find,
	const std::string& to_replace)
{
	const std::size_t pos = text.find(to_find);
	if (pos < text.length())
	{
		text.replace(pos, to_find.length(), to_replace);
	}
}

bool prompt_for_char(const char* prompt, char& readch)
{
	std::cout << prompt << std::endl;
	if (std::string tmp; std::getline(std::cin, tmp))
	{
		// Only accept single character input
		if (tmp.length() >= 1)
		{
			readch = tmp[0];
		}
		else
		{
			// For most input, char zero is an appropriate sentinel
			readch = '\0';
		}
		return true;
	}
	return false;
}