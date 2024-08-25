cmake_minimum_required(VERSION 3.21.0)
project(blackjack VERSION 0.1.0 LANGUAGES C)

add_subdirectory(game)

add_executable(blackjack main.c)
set_property(TARGET blackjack PROPERTY C_STANDARD 23)

target_link_libraries(blackjack PRIVATE game)
