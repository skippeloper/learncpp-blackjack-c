#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H
#include "../cards/Card.h"

extern const int deck_size;

/**
 * Represents a deck of cards.
 *
 * Members:
 *  `size` - size of the deck.
 *  `next_card_index` - index used by deal_card()
 *  `card` - holds all cards
 */
typedef struct Deck_s
{
    int size;
    int next_card_index;
    Card cards[];
} Deck;

/**
 * Allocate a new deck on the heap.
 *
 * @returns Pointer to the deck or `NULL` if there was an error.
 */
Deck* deck_create();

/**
 * Call free on the deck and set deck_ptr to `NULL`.
 */
void deck_destroy(Deck** deck_ptr);

/**
 * Shuffle a deck.
 */
void deck_shuffle(Deck* deck_ptr);

/**
 * Deal a card from the deck.
 *
 * @returns A card from the top of the deck.
 */
Card deck_deal_card(Deck* deck_ptr);
#endif
