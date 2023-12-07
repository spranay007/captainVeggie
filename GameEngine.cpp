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
    printField();
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
    //////////////////////////////////////////////////////////////
    playerScore = 0;

}
// Function to generate a random number between 0 and maxNumber
int generateRandomNumber(int maxNumber) {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 0 and maxNumber
    int randomNumber = std::rand() % (maxNumber + 1);

    return randomNumber;
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
        
    string veggieName[30]; 
    string veggieSymbol[30];
    int veggiePoints[30] ={0};
    int uniqueVegeCount =0;

    while (getline(file, line)) {
        cout << line << endl;
        istringstream veggieStream(line);
        
        getline(veggieStream, veggieName[uniqueVegeCount], ','); 
        getline(veggieStream, veggieSymbol[uniqueVegeCount], ',');
        veggieStream >> veggiePoints[uniqueVegeCount];
        
        cout << "Vegetable: " << veggieName[uniqueVegeCount] << ", Symbol: " << veggieSymbol[uniqueVegeCount] << ", Points: " << veggiePoints[uniqueVegeCount] << endl;
        uniqueVegeCount++;
    }

    int VegeToAllocated =0;
    for(int i = 0 ; i<uniqueVegeCount ; i++)
    {
        Veggie* newVeggie = new Veggie(veggieName[i], veggiePoints[i], veggieSymbol[i]);
        VegeToAllocated = generateRandomNumber(NUMBEROFVEGGIES-VegeToAllocated);
        for(int j = 0 ; j < VegeToAllocated ; j++)
        {
            int randomX, randomY;
            do {
                randomX = rand() % height;
                randomY = rand() % width;
            } while (field[randomX][randomY] != nullptr);
            field[randomX][randomY] = newVeggie;
            veggies.push_back(newVeggie);
        }            
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
        // Print the top border
        cout << "+"<<" ";
        for (size_t i = 0; i < width + 5; i++) {
            cout << "-"<<" ";
        }
        cout << "+" << endl;

        // Print the contents of the field
        for (int i = 0; i < height; i++) 
        {
            cout<<"|";
            for (int j = 0; j < width; j++) 
            {
                if (field[i][j] == nullptr) 
                {
                    cout << " - ";
                } else {
                    cout << " " << field[i][j]->getSymbol() << " ";
            }
        }
        cout << "|"<<endl;
    }

        // Print the bottom border
        cout << "+"<<" ";
        for (size_t i = 0; i < width + 5; i++) {
            cout << "-"<<" ";
        }
        cout << "+" << endl;
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
