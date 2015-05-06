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
#include "StockPile.h"
#include "DiscardPile.h"
#include "BuildPile.h"
#include "InvalidMoveException.h"
#include "TurnOverException.h"
#include <vector>
#include <sstream>

class Game {

  friend class TestMain;

private:
    std::vector<Player*> players;
    DrawPile* drawPile;
    BuildPile* buildPiles[4];
    int turn;

    /** Adds a Player to the Game. */
    void addPlayer(Player*);

    /** 
     * Generates the view of a Player. 
     * @param int the index of the Player who's view will be generated.
     */
    void generateView(std::stringstream*, int);
    
    /** Setter methods. */
    bool validMove(char, char) const;
    bool moveCard(char, char);

    /**
     * Returns whether the game is over.
     * @return whether the game is over
     */
    bool gameOver();
    
public:
    Game();
    Game(FILE* file);
 
 	/** Setter methods. */
    int setPlayers();
    void dealCards(int);
    void play();

    void promptMove();
  
    /** 
     * Prints the view of a Player. 
     * @param int the index of the Player who's view will be printed.
     */
    void printView(int);
  
};

#endif
