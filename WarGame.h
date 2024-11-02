#ifndef WARGAME_H
#define WARGAME_H

#include "Deck.h"
#include "SidePile.h"
#include <string>

class WarGame
{
private:
    Deck player_deck;
    Deck computer_deck;
    SidePile player_side_pile;
    SidePile computer_side_pile;
    int rounds;
    int rounds_played;

    void populate_decks();
    void play_round();
    void display_card_counts();

public:
    WarGame(int rounds = -1);
    void play_game();
};

#endif
