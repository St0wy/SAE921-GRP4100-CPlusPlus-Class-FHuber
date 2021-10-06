#pragma once
#include <string>

class IHelmet
{
public:
	virtual std::string get_helmet_color() = 0;
protected:
	std::string helmet_color_;
};

