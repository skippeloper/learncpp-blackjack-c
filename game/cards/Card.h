#ifndef BLACKJACK_CARDS_H
#define BLACKJACK_CARDS_H

/**
 * Represents a rank of a card.
 */
typedef enum Rank
{
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_max
} Rank;

/**
 * Represents the suit of a card.
 */
typedef enum Suit
{
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,
    suit_max
} Suit;

/**
 * Represents a card with a rank and suit.
 */
typedef struct Card_s
{
    Rank rank;
    Suit suit;
} Card;

/**
 * Default value for initialising a card.
 */
extern const Card card_default;

/**
 * Print a string representation of a card to console.
 */
void card_print(const Card* card);

/**
 * Print all possible card combinations
 */
void card_print_all();

/**
 * Retrieve the score of a card.
 *
 * @return `int` representing the card's score.
 */
int card_get_score(const Card* card);

/**
 * Array of string representations of card ranks.
 */
extern const char card_rank_names[rank_max];

/**
 * Array of scores for each rank.
 */
extern const int card_rank_scores[rank_max];

/**
 * Array of card ranks.
 */
extern const Rank card_all_ranks[rank_max];

/**
 * Array of string representations of card suits.
 */
extern const char card_suit_names[suit_max];

/**
 * Array of card suits.
 */
extern const Suit card_all_suits[suit_max];
#endif
