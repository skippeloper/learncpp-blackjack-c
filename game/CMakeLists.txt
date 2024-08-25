cmake_minimum_required(VERSION 3.21.0)
project(game VERSION 0.1.0 LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR})

add_library(game 
    cards/Card.c 
    cards/Card.h
    deck/Deck.c
    deck/Deck.h
    random/Random.c
    random/Random.h
    players/Player.c
    players/Player.h
    Game.c
    Game.h
)
set_property(TARGET game PROPERTY C_STANDARD 23)
