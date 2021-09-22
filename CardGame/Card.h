#pragma once
#include <string>
#include <array>
#include <vector>

#include "Value.h"
#include "Suit.h"

/**
 * \brief Represents a game card.
 */
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

	/**
	 * \brief Creates a printable string of the card.
	 * \return The string representation.
	 */
	std::string to_string() const;

	/**
	 * \brief Create a new vector of cards that is a full deck with every card in it.
	 * \return A new deck.
	 */
	static std::vector<Card> from_deck();
};

