/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Game.h
 */

#ifndef _GAME_H
#define _GAME_H

#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "DrawPile.h"
#include "BuildPile.h"
#include <vector>

class Game {
private:
    std::vector<Player*> players; // needs to be a pointer for dynamic binding
    DrawPile* drawPile;
    BuildPile* buildPiles[4];
    int turn;

    void addPlayer(Player* player);
    
public:
    Game();
    Game(FILE* file);
 
    void setPlayers();
    void dealCards();

    void makeMove(int i);

    void startGame();
    void loadGame();
    void saveGame();
    void endGame();
  
    void printView(int);
  
};

#endif
