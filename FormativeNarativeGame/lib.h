#pragma once
#include <string>
#include <iostream>

void find_n_replace(
	std::string& text,
	const std::string& to_find,
	const std::string& to_replace);

bool prompt_for_char(const char* prompt, char& readch);