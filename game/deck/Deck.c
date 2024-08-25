#include "Deck.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../random/Random.h"

const int deck_size = 52;

Deck* deck_create()
{
    size_t deck_mem_size = sizeof(Deck) + sizeof(Card[deck_size]);
    Deck* deck_ptr = malloc(deck_mem_size);

    if (deck_ptr == NULL)
    {
        perror("Failed to allocate memory for deck!");
        return NULL;
    }

    deck_ptr->size = deck_size;
    deck_ptr->next_card_index = 0;

    int index = 0;
    for (int suit_index = 0; suit_index < suit_max; ++suit_index)
    {
        for (int rank_index = 0; rank_index < rank_max; ++rank_index)
        {
            assert(rank_index < rank_max &&
                   "Rank index exceeded bounds of card_rank_names");
            assert(rank_index >= 0 && "Rank index may not be negative");

            assert(suit_index < suit_max &&
                   "Suit index exceeded bounds of card_suit_names");
            assert(rank_index >= 0 && "Suit index may not be negative");

            Card card = {card_all_ranks[rank_index],
                         card_all_suits[suit_index]};

            assert(index < deck_ptr->size && index >= 0 &&
                   "Index when creating deck was out of bounds!");

            deck_ptr->cards[index] = card;
            ++index;
        }
    }

    return deck_ptr;
}

void deck_destroy(Deck** deck_ptr)
{
    free(*deck_ptr);
    *deck_ptr = NULL;
}

void deck_shuffle(Deck* deck_ptr)
{
    if (deck_ptr->size > 1)
    {
        size_t i;
        for (i = 0; i < deck_ptr->size - 1; i++)
        {
            size_t j =
                i + randint(RAND_MAX) / (RAND_MAX / (deck_ptr->size - i) + 1);
            Card t = deck_ptr->cards[j];
            deck_ptr->cards[j] = deck_ptr->cards[i];
            deck_ptr->cards[i] = t;
        }
    }
}

Card deck_deal_card(Deck* deck_ptr)
{
    assert(deck_ptr->next_card_index < 52 && "Deck is empty!");
    return deck_ptr->cards[deck_ptr->next_card_index++];
}
