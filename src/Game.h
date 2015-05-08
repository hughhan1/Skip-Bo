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
#include "TopPile.h"
#include "InvalidMoveException.h"
#include "TurnOverException.h"
#include <fstream>
#include <vector>
#include <sstream>

class Game {

  friend class TestMain;

private:
    std::vector<Player*> players;
    DrawPile* drawPile;
    TopPile* buildPiles[4];
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

    /** Fills a player's hand. */
    void fillHand(int);

    void endMove();
    void addToDrawPile(int);
    
public:
    Game();
    Game(std::ifstream &inFile);
 
 	/** Setter methods. */
    int setPlayers();
    void dealCards(int);
    void play();

    void promptMove();

    void saveGame();
  
    /** 
     * Prints the view of a Player. 
     * @param int the index of the Player who's view will be printed.
     */
    void printView(int);
  
};

#endif
