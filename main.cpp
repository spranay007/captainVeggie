#include "GameEngine.h"
#include <iostream>

int main() {
    GameEngine game(10, 10);  // Assuming initial dimensions of the field are 10x10
    game.initializeGame();
    // game.intro();

    // int remainingVeggies = game.remainingVeggies();

    // while (remainingVeggies > 0) {
    //     // Output game information
    //     cout << "Remaining Vegetables: " << remainingVeggies << endl;
    //     cout << "Player's Score: " << game.getScore() << endl;

    //     // Print out the field
    //     game.printField();

    //     // Move the rabbits
    //     game.moveRabbits();

    //     // Move the captain
    //     game.moveCaptain();

    //     // Determine the new number of remaining vegetables
    //     remainingVeggies = game.remainingVeggies();
    // }

    // // Display Game Over information
    // game.gameOver();

    return 0;
}
