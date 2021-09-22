#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <termcolor/termcolor.hpp>
#include "Card.h"

void print_deck(std::array<Card, Card::NBR_CARDS_IN_DECK> deck);
void print_hand(const std::vector<Card>& hand);
std::vector<Card> pick_hand(const std::array<Card, Card::NBR_CARDS_IN_DECK> deck, int hand_size);

int main()
{
	const auto deck = Card::from_deck();
	std::cout << "Here is the full deck : "  << std::endl;
	print_deck(deck);
	std::cout << std::endl << std::endl;
	std::cout << "Here is your hand : " << std::endl;
	const std::vector<Card> hand = pick_hand(deck, 5);
	print_hand(hand);
}

/**
 * \brief Prints the deck in the terminal with colors.
 * \param deck Deck to print.
 */
void print_deck(const std::array<Card, Card::NBR_CARDS_IN_DECK> deck)
{
	for (Card card : deck)
	{
		if(card.get_suit() == Suit::Diamonds || card.get_suit() == Suit::Hearts)
		{
			std::cout << termcolor::red << card.to_string() << std::endl;
			std::cout << termcolor::reset;
		} else
		{
			std::cout << termcolor::blue << card.to_string() << std::endl;
			std::cout << termcolor::reset;
		}
	}
}

/**
 * \brief Prints a hand in the terminal with colors.
 * \param hand Hand to print.
 */
void print_hand(const std::vector<Card>& hand)
{
	for (Card card : hand)
	{
		if(card.get_suit() == Suit::Diamonds || card.get_suit() == Suit::Hearts)
		{
			std::cout << termcolor::red << card.to_string() << std::endl;
			std::cout << termcolor::reset;
		} else
		{
			std::cout << termcolor::blue << card.to_string() << std::endl;
			std::cout << termcolor::reset;
		}
	}
}

/**
 * \brief Picks a hand from the provided deck.
 * \param deck Deck to pick the hand from.
 * \param hand_size Size of the hand to pick.
 * \return The picked hand.
 */
std::vector<Card> pick_hand(const std::array<Card, Card::NBR_CARDS_IN_DECK> deck, int hand_size)
{
	// obtain a seed from the system clock
	typedef std::chrono::high_resolution_clock myclock;
	const uint32_t seed = static_cast<uint32_t>(myclock::now().time_since_epoch().count());

	// Declare dice lambda (to get random numbers)
	std::default_random_engine generator(seed);
	const std::uniform_int_distribution<int> distribution(0, Card::NBR_CARDS_IN_DECK - 1);

	std::vector<Card> hand;

	hand.reserve(hand_size);
	for (int i = 0; i < hand_size; ++i)
	{
		hand.push_back(deck[distribution(generator)]);
	}

	return hand;
}
