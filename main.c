#include <stdio.h>
#include <stdlib.h>

#include "game/Game.h"

int main()
{
    bool playerWon = blackjack();

    if (playerWon)
    {
        printf("You won!\n");
    }
    else
    {
        printf("You lose!\n");
    }
}
