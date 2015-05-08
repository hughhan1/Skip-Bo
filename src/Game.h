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
#include "ExistingPlayerException.h"
#include "NumPlayersException.h"
#include "InvalidInputException.h"
#include "InvalidMoveException.h"
#include "TurnOverException.h"
 
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>

class Game {

/* For testing purposes. */
friend class TestMain;

private:
    /** Instance variables. */
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
    
    /**
     * Returns if a move is valid.
     * @param char character representing where the card was moved from
     * @param char character representing where the card was moved to
     * @return if the move is valid
     */
    bool validMove(char, char) const;

    /**
     * Moves a card from one card structure to another.
     * @param char character representing where the card was moved from
     * @param char character representing where the card was moved to
     * @return if the turn is ended
     */
    bool moveCard(char, char);

    /**
     * Returns whether the game is over.
     * @return whether the game is over
     */
    bool gameOver();

    /** 
     * Fills a player's hand.
     * @param int the index of the player whose hand is to be filled
     */
    void fillHand(int);

    /** Processes what to do at the end of a move. */
    void endMove();

    /**
     * Shuffles and adds a completed build pile to the draw pile.
     * @param int the index of the build pile to be shuffled and added
     */
    void addToDrawPile(int);
    
public:
    Game();
    Game(std::ifstream &inFile);
	~Game();
 
 	/**
     * Initialize the players in the game.
     * @return the number of players
     */
    int setPlayers();

    /**
     * Deals cards to all of the players in the game.
     * @param int the number of players in the game
     */
    void dealCards(int);

    /** Plays the game. */
    void play();

    /** Prompts a player for a move. */
    void promptMove();

    /** Saves the game. */
    void saveGame();
  
    /** 
     * Prints the view of a Player. 
     * @param int the index of the Player who's view will be printed.
     */
    void printView(int);
  
};

#endif
