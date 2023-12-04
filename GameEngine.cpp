#include "GameEngine.h"
#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
    playerScore = 0;
}

void GameEngine::initVeggies() {
    // TODO: Implement the function
}

void GameEngine::initCaptain() {
    // TODO: Implement the function
}

void GameEngine::initRabbits() {
    // TODO: Implement the function
}

int GameEngine::remainingVeggies() const {
    // TODO: Implement the function
    return 0;
}

void GameEngine::intro() {
    // TODO: Implement the function
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
