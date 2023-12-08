#include <algorithm> 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>

#include "GameEngine.h"
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"
#include "Snake.h"

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
    initSnake();
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
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 0 and maxNumber
    randomNumber = rand() % (maxNumber + 1);
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

    // string veggieName[30]; 
    // string veggieSymbol[30];
    // int veggiePoints[30] ={0};
   
    
    while (getline(file, line)) {
        //cout << line << endl;
        istringstream veggieStream(line);
        /*
        getline(veggieStream, veggieName[uniqueVegeCount], ','); 
        getline(veggieStream, veggieSymbol[uniqueVegeCount], ',');
        veggieStream >> veggiePoints[uniqueVegeCount];
        
        cout << "Vegetable: " << veggieName[uniqueVegeCount] << ", Symbol: " << veggieSymbol[uniqueVegeCount] << ", Points: " << veggiePoints[uniqueVegeCount] << endl;
        uniqueVegeCount++;
        */
        string name, symbol;
        int points;

        getline(veggieStream, name, ',');
        getline(veggieStream, symbol, ',');
        veggieStream >> points;

        // cout << "Vegetable: " << name << ", Symbol: " << symbol << ", Points: " << points << endl;

        // Create a new Veggie object and add it to the vector
        Veggie* newVeggieRead = new Veggie(name, points, symbol);
        veggies.push_back(newVeggieRead);
    }
    int uniqueVegeCount = veggies.size();
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

    // for(int i = 0 ; i<uniqueVegeCount ; i++)
    // {
        /*
        Veggie* newVeggie = new Veggie(veggieName[i], veggiePoints[i], veggieSymbol[i]);
        //veggies.push_back(newVeggie);
        // Veggie* newVeggie = new Veggie(veggies[i]->getName(), veggies[i]->getSymbol(), veggies[i]->getPoints());
        for(int j = 0 ; j < temp[i] ; j++)
        {
            int randomX, randomY;
            do {
                randomX = rand() % height;
                randomY = rand() % width;
            } while (field[randomX][randomY] != nullptr);
            field[randomX][randomY] = newVeggie;    
        } 
        */

        int countFlag = 0;
        for (Veggie* veg : veggies) {
            for (int j = 0; j < temp[countFlag]; j++) {
                int randomX, randomY;
                do {
                    randomX = rand() % height;
                    randomY = rand() % width;
                } while (field[randomX][randomY] != nullptr);
                field[randomX][randomY] = veg;
                // cout << "Name: " << veg->getName() << endl;
            }
            countFlag++;
        }
    file.close();
    
    // cout << "Vegetables Loaded:" << endl;
    // for (const Veggie* veggie : veggies) {
    //     cout << "Name: " << veggie->getName() << ", Symbol: " << veggie->getSymbol() << ", Points: " << veggie->getPoints() << endl;
    // }
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

void GameEngine::initSnake() {
    snake = new Snake(0, 0);

    int randomX, randomY;
    do {
        randomX = rand() % height;
        randomY = rand() % width;
    } while (field[randomX][randomY] != nullptr);

    snake->setSnakeX(randomX);
    snake->setSnakeY(randomY);
    field[randomX][randomY] = snake;
}

int GameEngine::remainingVeggies() const {

    int veggieCount = 0;
    // Iterate through the entire field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Check if the current slot contains a Veggie object
            if (field[i][j] != nullptr && field[i][j]->getSymbol() != "V" && field[i][j]->getSymbol() != "R" && field[i][j]->getSymbol() != "S") {
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
    // ANSI escape codes for color
    const std::string RESET_COLOR = "\033[0m";
    const std::string YELLOW_COLOR = "\033[33m";  // Yellow for rabbits
    const std::string BLUE_COLOR = "\033[34m";    // Blue for captain
    const std::string GREEN_COLOR = "\033[32m";   // Green for vegetables
    const std::string RED_COLOR = "\033[31m";       //red for snake
        // Print the top border
        cout << "#"<<" ";
        for (int top = 0; top < width + 4; top++) {
            cout <<"#"<<" ";
        }
        cout << "#" << endl;

        // Print the contents of the field
        for (int i = 0; i < height; i++) 
        {
            cout<<"#";
            for (int j = 0; j < width; j++) 
            {
                if (field[i][j] == nullptr) 
                {
                    cout << "   ";
                } else {
                    if(field[i][j]->getSymbol() == "R") //rabbit
                    {
                        cout << YELLOW_COLOR  <<" "<< field[i][j]->getSymbol()<<" " << RESET_COLOR;
                    }
                    else if(field[i][j]->getSymbol() == "V") //captain
                    {
                        cout << BLUE_COLOR <<" "<< field[i][j]->getSymbol()<<" " << RESET_COLOR;
                    }
                    else if(field[i][j]->getSymbol() == "S") //snake
                    {
                        cout << RED_COLOR <<" "<< field[i][j]->getSymbol()<<" " << RESET_COLOR;
                    }
                    else //vegetables
                    {
                        cout << GREEN_COLOR << " " << field[i][j]->getSymbol() << " "<< RESET_COLOR;
                    }
                    // cout << " " << field[i][j]->getSymbol() << " ";
                }
        }
        cout << "#"<<endl;
    }

        // Print the bottom border
        cout << "#"<<" ";
        for (int bot = 0; bot < width + 4; bot++) {
            cout <<"#"<<" ";
        }
        cout << "#" << endl;
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
            else if ((field[newX][newY]->getSymbol() !="R") && (field[newX][newY]->getSymbol() !="V") && (field[newX][newY]->getSymbol() !="S")) 
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

void GameEngine::moveSnake(){
        int c_x = captain->getX();
        int c_y = captain->getY();
        int s_x = snake->getSnakeX();
        int s_y = snake->getSnakeY();
        int move = rand() % 2;

        int n_s_r, n_s_c;

        if (move == 0) {
            if (c_x > s_x) {
                n_s_r = s_x + 1;
                n_s_c = s_y;
            } else if (c_x < s_x) {
                n_s_r = s_x - 1;
                n_s_c = s_y;
            } else {
                move = 1;
            }
        }

        if (move == 1) {
            if (c_y > s_y) {
                n_s_c = s_y + 1;
                n_s_r = s_x;
            } else {
                n_s_c = s_y - 1;
                n_s_r = s_x;
            }
        }

        if (n_s_r == c_x && n_s_c == c_y) {
            int size = static_cast<int>(captain->getVeggieCollection().size());
            int min = std::min(size, 5);
            for (int i = 0; i < min; i++) {
                Veggie* veggie = captain->getVeggieCollection().back();
                captain->getVeggieCollection().pop_back();
                if (veggie != nullptr) {
                    playerScore -= veggie->getPoints();
                }
            }
            field[s_x][s_y] = nullptr;
            std::cout << "Snake Bite! You Lost "<<min<<" Veggies" << std::endl;
            initSnake();
        } else if (field[n_s_r][n_s_c] == nullptr) {
            field[s_x][s_y] = nullptr;
            snake->setSnakeX(n_s_r);
            snake->setSnakeY(n_s_c);
            field[n_s_r][n_s_c] = snake;
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
    }

}

void GameEngine::moveCaptain() {
    char direction;
    cout << "Enter direction to move the Captain (W/A/S/D): ";
    
    // Read a single character
    cin.get(direction);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            cout << "Invalid input. Captain did not move." << endl;
            return;
    }

    // Call the appropriate move function based on the direction
    if (tolower(direction) == 'w' || tolower(direction) == 's') {
        moveCptVertical(movement);
    } else if (tolower(direction) == 'a' || tolower(direction) == 'd') {
        moveCptHorizontal(movement);
    } else {
        cout << "Invalid input. Captain did not move." << endl;
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
