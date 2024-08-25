#ifndef BLACKJACK_RANDOM_H
#define BLACKJACK_RANDOM_H

/**
 * Seed the random number generator with the current time.
 */
void seed();

/**
 * Return a random number between 0 and n (not inclusive).
 *
 * @param n range of the random number generation.
 * @returns random int
 */
int randint(int n);

#endif
