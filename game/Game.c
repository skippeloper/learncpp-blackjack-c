#include "Game.h"

#include <stdio.h>
#include <stdlib.h>

#include "cards/Card.h"
#include "deck/Deck.h"
#include "players/Player.h"
#include "random/Random.h"

const int settings_bust_limit = 21;
const int settings_dealer_limit = 17;

/**
 * Plays the dealer turn.
 *
 * @param deck_ptr pointer to the deck to be used in the turn.
 * @param dealer_ptr pointer to the player that is the dealer.
 *
 * @return `bool` that is true if the dealer went bust.
 */
static bool __dealer_turn(Deck* deck_ptr, Player* dealer_ptr)
{
    while (dealer_ptr->score <= settings_dealer_limit)
    {
        Card card = deck_deal_card(deck_ptr);
        dealer_ptr->score += card_get_score(&card);

        printf("The dealer flips a ");
        card_print(&card);
        printf(". They now have: %i\n", dealer_ptr->score);

        if (dealer_ptr->score > settings_bust_limit)
        {
            printf("The dealer went bust!\n");
            return true;
        }
    }
    return false;
}

/**
 * Clears the input buffer up to the next newline or EOF.
 */
static void __clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Get the action of the player.
 *
 * @return `true` if player hits. `false` if player stands`
 */
static bool __get_player_action()
{
    while (true)
    {
        char action;
        printf("(h) to hit, or (s) to stand: ");
        int num_of_results = scanf("%c", &action);
        __clear_input_buffer();

        if (num_of_results == 1)
        {
            switch (action)
            {
            case 'h':
                return true;
            case 's':
                return false;
            default:
                printf("Input was not a valid action! Please try again\n");
                break;
            }
        }
        else
        {
            printf("Input was incorrect! Please try again!\n");
        }
    }
}

/**
 * Plays the player's turn.
 *
 * @param deck_ptr pointer to the deck to be used in the turn
 * @param player_ptr pointer to the player to be used in the turn
 *
 * @return `bool` that is true if the player went bust
 */
static bool __player_turn(Deck* deck_ptr, Player* player_ptr)
{
    while (player_ptr->score <= settings_bust_limit)
    {
        bool player_chose_hit = __get_player_action();

        if (player_chose_hit)
        {
            Card card = deck_deal_card(deck_ptr);
            player_ptr->score += card_get_score(&card);

            printf("You were dealt ");
            card_print(&card);
            printf(". You now have: %i\n", player_ptr->score);
        }
        else
        {
            return false;
        }
    }
    printf("You went bust!\n");
    return true;
}

bool blackjack()
{
    seed();
    Deck* deck_ptr = deck_create();

    if (deck_ptr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    deck_shuffle(deck_ptr);

    Player dealer = player_default;
    Player player = player_default;

    Card dealer_card = deck_deal_card(deck_ptr);
    dealer.score = card_get_score(&dealer_card);
    Card player_card = deck_deal_card(deck_ptr);
    player.score += card_get_score(&player_card);

    printf("Dealer is showing: %i\n", dealer.score);
    printf("You have score: %i\n", player.score);

    bool playerWentBust = __player_turn(deck_ptr, &player);
    if (playerWentBust)
    {
        deck_destroy(&deck_ptr);
        return false;
    }

    bool dealerWentBust = __dealer_turn(deck_ptr, &dealer);
    if (dealerWentBust)
    {
        deck_destroy(&deck_ptr);
        return true;
    }

    deck_destroy(&deck_ptr);
    return dealer.score < player.score;
}
