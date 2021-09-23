#include <iostream>
#include <string>

bool is_letter(char c);
std::string shift_text(const std::string& text);

int main()
{
	std::string text;
	std::cout << "Entrez du texte" << std::endl;
	std::getline(std::cin, text);
	const std::string shifted_text = shift_text(text);
	std::cout << "Shifted : " << shifted_text << std::endl;
}

bool is_letter(const char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

std::string shift_text(const std::string& text)
{
	std::string shifted_text;
	for (char c : text)
	{
		if (is_letter(c))
		{
			if (c == 'z')
			{
				c = 'a';
			}
			else if (c == 'Z')
			{
				c = 'A';
			}
			else
			{

				c++;
			}
		}
		shifted_text += c;
	}

	return shifted_text;
}
