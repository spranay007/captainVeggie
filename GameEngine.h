#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>

class FieldInhabitant;
class Captain;
class Rabbit;
class Veggie;

class GameEngine {
public:
    GameEngine(int height, int width);
    ~GameEngine();

    void initializeGame();
    void intro();
    void printField();
    void moveRabbits();
    void moveCaptain();
    void gameOver();

    int getScore() const;
    int remainingVeggies() const;

private:
    FieldInhabitant*** field;
    int height;
    int width;
    int playerScore;
    const static int NUMBEROFVEGGIES = 30;
    const static int NUMBEROFRABBITS = 5;
    Captain* captain;
    std::vector<Rabbit*> rabbits;
    std::vector<Veggie*> veggies;

    void initVeggies();
    void initCaptain();
    void initRabbits();
    void moveCptVertical(int movement);
    void moveCptHorizontal(int movement);
};

#endif // GAMEENGINE_H
