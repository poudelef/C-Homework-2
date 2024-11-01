#include "WarGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void WarGame::populate_decks()
{
    for (int i = 0; i < 10; ++i)
    {
        player_deck.add(rand() % 10 + 1);
        computer_deck.add(rand() % 10 + 1);
    }
}

void WarGame::play_round()
{
    int player_card = player_deck.draw();
    int computer_card = computer_deck.draw();

    if (player_card == -1 || computer_card == -1)
    {
        return;
    }

    std::cout << "Choose action ('push' to add to side pile, 'pull' to draw extra, or 'play' to continue with one card): ";
    std::string action;
    std::cin >> action;

    if (action == "push")
    {
        player_side_pile.push(player_card);
        player_card = player_deck.draw();
    }
    else if (action == "pull")
    {
        int side_card = player_side_pile.pop();
        if (side_card != -1)
        {
            player_card += side_card;
        }
    }

    if (rand() % 2 == 1 && computer_side_pile.size() > 0)
    {
        int side_card = computer_side_pile.pop();
        computer_card += side_card;
    }

    std::cout << "Player plays: " << player_card << ", Computer plays: " << computer_card << std::endl;
    if (player_card > computer_card)
    {
        std::cout << "Player wins the round.\n";
        player_deck.add(player_card);
        player_deck.add(computer_card);
    }
    else
    {
        std::cout << "Computer wins the round.\n";
        computer_deck.add(player_card);
        computer_deck.add(computer_card);
    }
}

void WarGame::display_card_counts()
{
    std::cout << "Player deck: " << player_deck.remaining_cards()
              << " cards, Side pile: " << player_side_pile.size() << " cards\n";
    std::cout << "Computer deck: " << computer_deck.remaining_cards() << " cards\n";
}

WarGame::WarGame(int rounds) : rounds(rounds), rounds_played(0)
{
    populate_decks();
    // Shuffle the decks before starting the game
}

void WarGame::play_game()
{
    std::cout << "Welcome to the War Game!\n";
    while ((rounds == -1 || rounds_played < rounds) &&
           player_deck.remaining_cards() > 0 &&
           computer_deck.remaining_cards() > 0)
    {
        display_card_counts();
        play_round();
        rounds_played++;
    }

    if (player_deck.remaining_cards() > computer_deck.remaining_cards())
    {
        std::cout << "Player wins the game!\n";
    }
    else if (computer_deck.remaining_cards() > player_deck.remaining_cards())
    {
        std::cout << "Computer wins the game!\n";
    }
    else
    {
        std::cout << "It's a tie!\n";
    }
}
