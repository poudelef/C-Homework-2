#include "WarGame.h"
#include <iostream>
#include <string>
#include <ctime>

int main()
{
    // Seed random number generator for card shuffling
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Enter 1 to play until one player runs out of cards, or enter number of rounds: ";
    std::string input;
    std::cin >> input;
    int rounds = (input == "1") ? -1 : std::stoi(input);

    WarGame game(rounds);
    game.play_game();

    return 0;
}
