#include "Card.h"

#include <assert.h>
#include <stdio.h>

const Card card_default = {rank_ace, suit_club};

const char card_rank_names[rank_max] = {'A', '2', '3', '4', '5', '6', '7',
                                        '8', '9', 'T', 'J', 'Q', 'K'};

const Rank card_all_ranks[rank_max] = {
    rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,    rank_7,
    rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king,
};

const int card_rank_scores[rank_max] = {11, 2, 3,  4,  5,  6, 7,
                                        8,  9, 10, 10, 10, 10};

const char card_suit_names[suit_max] = {'C', 'D', 'H', 'S'};

const Suit card_all_suits[suit_max] = {
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,
};

void card_print(const Card* card)
{
    printf("%c%c", card_rank_names[card->rank], card_suit_names[card->suit]);
}

void card_print_all()
{
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

            printf("%c%c ", card_rank_names[rank_index],
                   card_suit_names[suit_index]);
        }
    }
}

int card_get_score(const Card* card) { return card_rank_scores[card->rank]; }
