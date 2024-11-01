#include "WarGame.h"
#include <iostream>
#include <string>
#include <ctime>

int main()
{
    // Seed random number generator for card shuffling
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Enter 0 to play until one player runs out of cards, or enter number of rounds: ";
    std::string input;
    std::cin >> input;

    int rounds;

    if (input == "0") {
        rounds = -1;
    }
    else {
        rounds = std::stoi(input);
    }


    WarGame game(rounds);
    game.play_game();

    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.get(); 

    return 0;
}
