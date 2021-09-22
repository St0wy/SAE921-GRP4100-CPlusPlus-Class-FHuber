#include <string>
#include <array>
#include "Card.h"


Card::Card(const Value value, const Suit suit) : value_(value), suit_(suit)
{
}

Card::Card() : Card(Value::Ace, Suit::Hearts)
{
}

Value Card::get_value() const
{
	return value_;
}

Suit Card::get_suit() const
{
	return suit_;
}

std::string Card::to_string() const
{
	std::string suit_text;
	std::string value_text;

	switch (value_)
	{
	case Value::Ace:
		value_text = "Ace";
		break;
	case Value::Jack:
		value_text = "Jack";
		break;
	case Value::Queen:
		value_text = "Queen";
		break;
	case Value::King:
		value_text = "King";
		break;
	default:
		value_text = std::to_string(static_cast<int>(value_));
		break;
	}

	switch (suit_)
	{
	case Suit::Clubs:
		suit_text = "Clubs";
		break;
	case Suit::Diamonds:
		suit_text = "Diamonds";
		break;
	case Suit::Hearts:
		suit_text = "Hearts";
		break;
	case Suit::Spades:
		suit_text = "Spades";
		break;
	}

	return value_text + " of " + suit_text;
}

std::vector<Card> Card::from_deck()
{
	std::vector<Card> cards;

	for (int suit_index = 0; suit_index < NBR_SUITS; ++suit_index)
	{
		for (int value_index = 0; value_index < NBR_VALUES; ++value_index)
		{
			cards.emplace_back(static_cast<Value>(value_index + 1), static_cast<Suit>(suit_index));
		}
	}
	return cards;
}

