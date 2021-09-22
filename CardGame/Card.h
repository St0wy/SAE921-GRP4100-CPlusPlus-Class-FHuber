#pragma once
#include <string>
#include <array>
#include "Value.h"
#include "Suit.h"

class Card
{
	Value value_;
	Suit suit_;
public:
	static constexpr int NBR_SUITS = 4;
	static constexpr int NBR_VALUES = 13;
	static constexpr int NBR_CARDS_IN_DECK = NBR_SUITS * NBR_VALUES;

	Card(Value value, Suit suit);
	Card();
	Value get_value() const;
	Suit get_suit() const;
	std::string to_string() const;
	static std::array<Card, NBR_CARDS_IN_DECK> from_deck();
};

