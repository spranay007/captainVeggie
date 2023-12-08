#include "GameEngine.h"
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"
#include <algorithm> 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>

GameEngine::GameEngine(int height, int width)
    : height(height), width(width), playerScore(0), captain(nullptr), field(nullptr) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

GameEngine::~GameEngine() {
   
}

void GameEngine::initializeGame() {
    initVeggies();
    initCaptain();
    initRabbits();
    printField();
    /////////////////////////////////////////////////////////
    // cout << "Current Field:" << endl;
    // for (int i = 0; i < height; ++i) {
    //     for (int j = 0; j < width; ++j) {
    //         if (field[i][j] == nullptr) {
    //             cout << " - ";
    //         } else {
    //             cout << " " << field[i][j]->getSymbol() << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;    
    //////////////////////////////////////////////////////////
    playerScore = 0;

}
// Function to generate a random number between 0 and maxNumber
int generateRandomNumber(int maxNumber) {
    int randomNumber = 0;
    // Seed the random number generator with the current time
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 0 and maxNumber
    randomNumber = std::rand() % (maxNumber + 1);
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
    // Read the label and discard it (assuming it's not needed)
    getline(iss, label, ',');

    // Read the values of x and y
    iss >> height;
    getline(iss, label, ',');
    iss >> width;
    
    // Filling the field with null pointers first
    field = new FieldInhabitant**[height];
    for (int i = 0; i < height; ++i) {
        field[i] = new FieldInhabitant*[width];
        for (int j = 0; j < width; ++j) {
            field[i][j] = nullptr;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////
    // Time to seed
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

    int vegeLeftToAllocate = NUMBEROFVEGGIES;
    int vegeAllocated = 0;
    int temp[NUMBEROFVEGGIES] ={0};
    int totalVege = 0; //track sum
    ////////////////////////////////////////////////////////////////////////////////////////////
    for(int ijk=0 ; ijk<uniqueVegeCount-1 ; ijk++)
    {
       vegeAllocated = generateRandomNumber(vegeLeftToAllocate-totalVege);
       
       totalVege = totalVege + vegeAllocated;
       if(totalVege==NUMBEROFVEGGIES)
       {
           temp[ijk] = vegeAllocated;//fill the nth value and then break as sum is reached
           break;
       }
       else if(totalVege > NUMBEROFVEGGIES)
       {
           temp[ijk] = NUMBEROFVEGGIES - totalVege;
           break;
       }
       else if(totalVege < NUMBEROFVEGGIES)
       {
           temp[ijk] = vegeAllocated;
       }
       if(ijk == uniqueVegeCount-2)
       {
          temp[uniqueVegeCount-1] = NUMBEROFVEGGIES - totalVege;
       }
    }
    //////////////////////////////////////////////////////////////////////////////////////

    for(int i = 0 ; i<uniqueVegeCount ; i++)
    {
        Veggie* newVeggie = new Veggie(veggieName[i], veggiePoints[i], veggieSymbol[i]);
        veggies.push_back(newVeggie);

        for(int j = 0 ; j < temp[i] ; j++)
        {
            int randomX, randomY;
            do {
                randomX = rand() % height;
                randomY = rand() % width;
            } while (field[randomX][randomY] != nullptr);
            field[randomX][randomY] = newVeggie;    
        }          
    }
    file.close();
    
    cout << "Vegetables Loaded:" << endl;
    for (const Veggie* veggie : veggies) {
        cout << "Name: " << veggie->getName() << ", Symbol: " << veggie->getSymbol() << ", Points: " << veggie->getPoints() << endl;
    }
}


void GameEngine::initCaptain() {
    captain = new Captain(0, 0);

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

    int veggieCount = 0;
    // Iterate through the entire field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Check if the current slot contains a Veggie object
            if (field[i][j] != nullptr && field[i][j]->getSymbol() != "V" && field[i][j]->getSymbol() != "R") {
                veggieCount++;
            }
        }
    }

    return veggieCount;
    
   //return veggies.size();
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
    for (Rabbit* rabbit : rabbits) 
    {
        int moveX = std::rand() % 3 - 1;  // Random movement in x direction (-1, 0, 1)
        int moveY = std::rand() % 3 - 1;  // Random movement in y direction (-1, 0, 1)
        
        int oldX = rabbit->getX();
        int oldY = rabbit->getY();

        int newX = oldX + moveX;
        int newY = oldY + moveY;

        // Check if new location is within the boundaries of the field
        if (newX >= 0 && newX < height && newY >= 0 && newY < width) 
        {
            // Check if the new location is unoccupied
            if (field[newX][newY] == nullptr) 
            {
                // Update Rabbit's position in the field
                field[rabbit->getX()][rabbit->getY()] = nullptr;
                rabbit->setX(newX);
                rabbit->setY(newY);
                field[newX][newY] = rabbit;
                // field[oldX][oldY] = nullptr;
            } 
            else if ((field[newX][newY]->getSymbol() !="R") && (field[newX][newY]->getSymbol() !="V")) 
            {
                // If Rabbit moves into a Veggie, remove the Veggie
                ////////////////////////////////////////////////////////////////////////////////////////////
                /*
                Veggie* veggie = dynamic_cast<Veggie*>(field[newX][newY]);
                auto it = find(veggies.begin(), veggies.end(), veggie);      
                if (it != veggies.end()) { // If element found         
                //newVector.push_back(*it); // Push the found element into the new vector         
                veggies.erase(it); // Remove the element from the original vector  
                } 
                */  
                ////////////////////////////////////////////////////////////////////////////////////////////
                field[rabbit->getX()][rabbit->getY()] = nullptr;
                rabbit->setX(newX);
                rabbit->setY(newY);
                field[newX][newY] = rabbit;

            }
        }
    }
}

void GameEngine::moveCptVertical(int movement) {
    int currentX = captain->getX();
    int currentY = captain->getY();

    // Calculate new position
    int newX = currentX + movement;
    int newY = currentY;

    // Check if the new position is within the boundaries
    if (newX >= 0 && newX < height) {
        // Check if the new position is unoccupied
        if (field[newX][newY] == nullptr) {
            // Move the Captain to the new position
            field[currentX][currentY] = nullptr;
            field[newX][newY] = captain;
            captain->setX(newX);
        } else if ((field[newX][newY]->getSymbol() != "R") && (field[newX][newY]->getSymbol() != "S")){
            // Captain moved into a space occupied by Veggie
            Veggie* veggie = dynamic_cast<Veggie*>(field[newX][newY]);
            field[currentX][currentY] = nullptr;
            field[newX][newY] = captain;
            captain->setX(newX);
            // Output and update score
            std::cout << "Delicious vegetable found: " << veggie->getName() << std::endl;
            captain->addVeggie(veggie);
            playerScore = playerScore + (veggie->getPoints());
            ////////////////////////////////////////////////////////////////////////////////////////////
            /*
            auto it = find(veggies.begin(), veggies.end(), veggie);      
            if (it != veggies.end()) { // If element found         
            //newVector.push_back(*it); // Push the found element into the new vector         
            veggies.erase(it); // Remove the element from the original vector    
            */ 
            ////////////////////////////////////////////////////////////////////////////////////////////
            //}

        } else if (field[newX][newY]->getSymbol() == "R") {
            // Captain moved into a space occupied by Rabbit
            std::cout << "Do not step on the rabbits!" << std::endl;
            // Do not move the Captain object
        }

        // Set the Captain's previous location in the field to nullptr
        // field[currentX][currentY] = nullptr;
    }
}

// Function to move Captain object horizontally
void GameEngine::moveCptHorizontal(int movement) {
    int currentX = captain->getX();
    int currentY = captain->getY();

    // Calculate new position
    int newX = currentX;
    int newY = currentY + movement;

    // Check if the new position is within the boundaries
    if (newY >= 0 && newY < width) {
        // Check if the new position is unoccupied
        if (field[newX][newY] == nullptr) {
            // Move the Captain to the new position
            field[currentX][currentY] = nullptr;
            field[newX][newY] = captain;
            captain->setY(newY);
        } else if ((field[newX][newY]->getSymbol() != "R") && (field[newX][newY]->getSymbol() != "S")) {
            // Captain moved into a space occupied by Veggie
            Veggie* veggie = dynamic_cast<Veggie*>(field[newX][newY]);
            field[currentX][currentY] = nullptr;
            field[newX][newY] = captain;
            captain->setY(newY);
            // Output and update score
            cout << "Delicious vegetable found: " << veggie->getName() << endl;
            captain->addVeggie(veggie);
            playerScore = playerScore + (veggie->getPoints());
            ////////////////////////////////////////////////////////////////////////////////////////////
            /*
            auto it = find(veggies.begin(), veggies.end(), veggie);      
            if (it != veggies.end()) { // If element found         
            //newVector.push_back(*it); // Push the found element into the new vector         
            veggies.erase(it); // Remove the element from the original vector
            */
            ////////////////////////////////////////////////////////////////////////////////////////////     
            //}

        } else if (field[newX][newY]->getSymbol() == "R") {
            // Captain moved into a space occupied by Rabbit
            std::cout << "Do not step on the rabbits!" << std::endl;
            // Do not move the Captain object
        }

        // Set the Captain's previous location in the field to nullptr
        // field[currentX][currentY] = nullptr;
    }

}

void GameEngine::moveCaptain() {
char direction;
    std::cout << "Enter direction to move the Captain (W/A/S/D): ";
    std::cin >> direction;

    int movement = 0;

    // Determine the movement based on user input
    switch (tolower(direction)) {
        case 'w':
            movement = -1; // Move up
            break;
        case 's':
            movement = 1; // Move down
            break;
        case 'a':
            movement = -1; // Move left
            break;
        case 'd':
            movement = 1; // Move right
            break;
        default:
            std::cout << "Invalid input. Captain did not move." << std::endl;
            return;
    }

    // Check the player's input using a switch and call the appropriate move function
    switch (tolower(direction)) {
        case 'w':
        case 's':
            moveCptVertical(movement);
            break;
        case 'a':
        case 'd':
            moveCptHorizontal(movement);
            break;
        default:
            std::cout << "Invalid input. Captain did not move." << std::endl;
            break;
    }
}

void GameEngine::gameOver() {
std::cout << "Game Over!" << std::endl;
    
    // Get the number of vegetables harvested by the Captain
    const std::vector<Veggie*>& harvestedVeggies = captain->getVeggieCollection();
    int numHarvestedVeggies = static_cast<int>(harvestedVeggies.size());

    // Output the number of vegetables harvested
    std::cout << "Vegetables harvested by Captain: " << numHarvestedVeggies << std::endl;

    // Output the names of all vegetables harvested by the Captain
    std::cout << "Vegetable names:" << std::endl;
    for (const Veggie* veggie : harvestedVeggies) {
        std::cout << "- " << veggie->getName() << std::endl;
    }

    // Output the player's score
    std::cout << "Your Score: " << getScore() << std::endl;


}
