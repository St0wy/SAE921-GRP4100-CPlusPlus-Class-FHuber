#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <termcolor/termcolor.hpp>
#include "Card.h"

void print_cards(const std::vector<Card>& cards);
std::vector<Card> pick_hand(std::vector<Card> deck, int hand_size);

int main()
{
	const auto deck = Card::from_deck();
	std::cout << "Here is the full deck : " << std::endl;
	print_cards(deck);
	std::cout << std::endl << std::endl;
	std::cout << "Here is your hand : " << std::endl;
	const std::vector<Card> hand = pick_hand(deck, 5);
	print_cards(hand);
}

/**
 * \brief Prints cards in the terminal with colors.
 * \param cards Cards to print.
 */
void print_cards(const std::vector<Card>& cards)
{
	for (Card card : cards)
	{
		if (card.get_suit() == Suit::Diamonds || card.get_suit() == Suit::Hearts)
		{
			std::cout << termcolor::red << card.to_string() << std::endl;
			std::cout << termcolor::reset;
		}
		else
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
std::vector<Card> pick_hand(std::vector<Card> deck, const int hand_size)
{
	// obtain a seed from the system clock
	typedef std::chrono::high_resolution_clock myclock;
	const uint32_t seed = static_cast<uint32_t>(myclock::now().time_since_epoch().count());

	// Declare dice lambda (to get random numbers)
	std::default_random_engine generator(seed);

	std::vector<Card> hand;

	hand.reserve(hand_size);
	for (int i = 0; i < hand_size; ++i)
	{
		// - i so that it doesn't go out of the vector (since we erase at the end)
		const std::uniform_int_distribution<int> distrib(0, Card::NBR_CARDS_IN_DECK - 1 - i);
		const int index = distrib(generator);
		hand.push_back(deck[index]);
		deck.erase(deck.begin() + index);
	}

	return hand;
}
