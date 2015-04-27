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

    /** Adds a Player to the Game. */
    void addPlayer(Player*);

    /** Allows an individual Player to make a move. */
    void move(int);

    /** 
     * Generates the view of a Player. 
     * @param int the index of the Player who's view will be generated.
     */
    std::stringstream* generateView(int);

    /** Getter methods. */
    DrawPile* getDrawPile() const;
    BuildPile* getBuildPiles(int i) const;
    
public:
    Game();
    Game(FILE* file);
 
    void setPlayers();
    void dealCards();
    void play();
  
    /** 
     * Prints the view of a Player. 
     * @param int the index of the Player who's view will be printed.
     */
    void printView(int);
  
};

#endif
