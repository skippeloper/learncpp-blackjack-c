#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include <stdbool.h>

/**
 * Plays a game of blackjack.
 *
 * @returns `true` if the player won. `false` otherwise.
 */
bool blackjack();

/**
 * Any score above this number will result in a bust.
 */
extern const int settings_bust_limit;

/**
 * Any score above this number will result in the dealer turn ending.
 */
extern const int settings_dealer_limit;

#endif
