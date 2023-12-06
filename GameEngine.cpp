#include "GameEngine.h"
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

GameEngine::GameEngine(int height, int width)
    : height(height), width(width), playerScore(0), captain(nullptr), field(nullptr) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

GameEngine::~GameEngine() {
    // Implement destructor to free memory
}

void GameEngine::initializeGame() {
    initVeggies();
    initCaptain();
    initRabbits();
    std::cout << "Current Field:" << std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (field[i][j] == nullptr) {
                std::cout << " - ";
            } else {
                std::cout << " " << field[i][j]->getSymbol() << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    //initRabbits();
    playerScore = 0;
}

void GameEngine::initVeggies() {
    string filename;
    ifstream file;

    do {
        cout << "Enter the name of the veggie file: ";
        cin >> filename;

        file.open(filename);

        if (!file) {
            cout << "File not found. Please enter a valid filename." << endl;
        }

    } while (!file);

    // Read the line from the file
    string line;
    getline(file, line);

    // Create an istringstream object
    istringstream iss(line);

    // Variables to store the parsed values
    string label;
    int x, y;

    // Read the label and discard it (assuming it's not needed)
    getline(iss, label, ',');

    // Read the values of x and y
    iss >> height;
    getline(iss, label, ',');
    iss >> width;
    

    field = new FieldInhabitant**[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new FieldInhabitant*[width];
        for (int j = 0; j < width; ++j) {
            field[i][j] = nullptr;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////

    srand(static_cast<unsigned int>(time(nullptr)));

    while (getline(file, line)) {
        cout << line << endl;
        istringstream veggieStream(line);
        //string label2;
        string veggieName, veggieSymbol;
        int veggiePoints;
        getline(veggieStream, veggieName, ','); 
        getline(veggieStream, veggieSymbol, ',');
        veggieStream >> veggiePoints;
        cout << "Vegetable: " << veggieName << ", Symbol: " << veggieSymbol << ", Points: " << veggiePoints << endl;
        Veggie* newVeggie = new Veggie(veggieName, veggiePoints, veggieSymbol);

        int randomX, randomY;
        do {
            randomX = rand() % height;
            randomY = rand() % width;
        } while (field[randomX][randomY] != nullptr);

        field[randomX][randomY] = newVeggie;
        veggies.push_back(newVeggie);
    }

    file.close();
    
    cout << "Vegetables Loaded:" << endl;
    for (const Veggie* veggie : veggies) {
        cout << "Name: " << veggie->getName() << ", Symbol: " << veggie->getSymbol() << ", Points: " << veggie->getPoints() << endl;
    }
}


void GameEngine::initCaptain() {
    captain = new Captain(0, 0); // Initializing at (0, 0) for simplicity

    int randomX, randomY;
    do {
        randomX = rand() % height;
        randomY = rand() % width;
    } while (field[randomX][randomY] != nullptr);

    captain->setX(randomX);
    captain->setY(randomY);
    field[randomX][randomY] = captain;
}

void GameEngine::initRabbits() 
{
    // TODO: Implement the function
        for (int i = 0; i < NUMBEROFRABBITS; i++) 
        {
            while (true) 
            {
                int randomX = rand() % height;
                int randomY = rand() % width;
                if (field[randomX][randomY] == nullptr) 
                {
                    Rabbit* x = new Rabbit(randomX, randomY);
                    field[randomX][randomY] = x;
                    rabbits.push_back(x);
                    break;
                }
            }
        }
}

int GameEngine::remainingVeggies() const {
    // TODO: Implement the function
    int veggie_count = 0;
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            if (field[i][j] != nullptr && field[i][j]->getSymbol()!="R" && field[i][j]->getSymbol()!= "V" && field[i][j]->getSymbol()!="S") 
            {
                veggie_count++;
            }
        }
    }
                
    return veggie_count;
}

void GameEngine::intro() {
    // TODO: Implement the function
    cout<<"Welcome to Captain Veggie!"<<endl;
    cout<<"The rabbits have invaded your garden"<<endl;
    cout<<"So, you must harvest as many vegetables as possible before the rabbits eat them all!"<<endl;
    cout<<"Each vegetable is worth a different number of points so go for the high score!"<<endl;
    cout<<"The vegetables are:"<<endl;
    for (const Veggie* veggie : veggies) {
        cout << "Name: " << veggie->getName() << ", Symbol: " << veggie->getSymbol()<<endl;
    }
    cout<<"Captain Veggie is V, and the rabbits are R's"<<endl;
    cout<<"Good Luck!"<<endl;

}

void GameEngine::printField() {
    // TODO: Implement the function
}

int GameEngine::getScore() const {
    return playerScore;
}

void GameEngine::moveRabbits() {
    // TODO: Implement the function
}

void GameEngine::moveCptVertical(int movement) {
    // TODO: Implement the function
}

void GameEngine::moveCptHorizontal(int movement) {
    // TODO: Implement the function
}

void GameEngine::moveCaptain() {
    // TODO: Implement the function
}

void GameEngine::gameOver() {
    // TODO: Implement the function
}
