/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Game.cpp
 */

#include <iostream>
#include <sstream>
#include "Game.h"

using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;

/** Public */

Game::Game() { 
    this->drawPile = new DrawPile();
    for (int i = 0; i < 4; i++) {
        this->buildPiles[i] = new BuildPile();
    }
    turn = 0;
}

Game::Game(FILE* file) {
    // TO DO
}

int Game::setPlayers() {
    
    int numPlayers;
    std::string name;
    int input;
    int num;

    cout << "Please enter the number of players: ";
    cin >> numPlayers;
    cout << endl;

    for (int i = 0; i < numPlayers; i++) {
        cout << "Please enter the name of Player " << i + 1 << ": ";
        cin >> name;

        cout << "If this player is a human enter 0. If this player is a computer enter 1." << std::endl;
        cin >> input;
        cout << endl;

    if (input == 0)
        addPlayer(new Human(name));
    else
        addPlayer(new Computer(name));
    }
    
    /* Shuffle the Draw Pile. */
    drawPile->shuffle();

    /* Prompts the user for the stock pile size. */
    cout << "Initial Stock pile size: ";
    cin >> num;
    cout << endl;

    return num;
}

void Game::dealCards(int num) {

    int numPlayers = players.size();
        
    /* Deals the cards from the draw pile to each player. */
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            players[i]->addCardToHand(drawPile->remove());
        }
        for(int j = 0; j < num; j++){
            players[i]->addCardToStockPile(drawPile->remove());
        }
    }   
    
}

void Game::play() {

    int numPlayers = this->players.size();

    while (!gameOver()) {
        printView(this->turn % numPlayers);
        promptMove();
    }

}

void Game::printView(int i) {
    stringstream lines[11];
    cout << this->players[i]->getName() << "'s turn!" << endl;
    generateView(lines, i);
    for (int a = 0; a < 11; a++) {
        cout << lines[a].str() << endl;        
    }    
}

/** Private */

void Game::addPlayer(Player* player){
    players.push_back(player);
}

void  Game::generateView(stringstream *lines, int i) {
    Player * player = this->players[i];
    int numPlayers = this->players.size();
    int value;
    
    for (int a = 0; a < numPlayers; a++) {
        if (player != this->players[a]) {
            Player* p = this->players[a];

            lines[0] << p->getName() << "\t\t\t";
            lines[1] << "(" << p->getStockPile()->getSize() << ")\tDiscard\t\t";

            value = p->getStockPile()->top()->getVal();
            if (value < 10) 
                lines[2] << " ";
            lines[2] << " " << p->getStockPile()->top()->getVal() << " \t";

            for (int b = 0; b < 4; b++) {
                if (p->getDiscardPiles()[b]->isEmpty()) {
                    lines[2] << "- ";
                } else {
                    lines[2] << p->getDiscardPiles()[b]->top()->getVal();
                }
            }
            lines[2] << "\t";
        } 
    }
    
    lines[3] << "";
    lines[4] << "Build Piles:\t[a]\t[b]\t[c]\t[d]";

    for (int a = 0; a < 4; a++) {
        if (this->buildPiles[a]->isEmpty())
            lines[5] << "- ";
        else 
            lines[5] << this->buildPiles[a]->getSize() << " ";
    }

    lines[6] << "";
    lines[7] << player->getName();
    lines[8] << "Hand\t\t\tDiscard Piles\t\tStock Pile";
    lines[9] << "[1] [2] [3] [4] [5] \t[6] [7] [8] [9] \t[0]";

    for (int i = 0; i < 5; i++) {
        if (player->getHand()->getCard(i) != nullptr) {
            int value = player->getHand()->getCard(i)->getVal();

            if (value < 10) 
                lines[10] << " ";
            lines[10] << value << "  ";
        }
        else {
            lines[10] << " - ";
        }
    }

    lines[10] << "    ";
    
    for (int a = 0; a < 4; a++){
        if (!player->getDiscardPiles()[a]->isEmpty()) {
            lines[10] << player->getDiscardPiles()[a]->top()->getVal()<<" ";
        }
        else {
            lines[10] << " -  ";
        }
    }

    lines[10] << "\t " << player->getStockPile()->top()->getVal() << "  (" << player->getStockPile()->getSize() << ")";
    
}

void Game::promptMove() {
  Player * player = players[this->turn % players.size()];

    char moveFrom;
    char moveTo;

    try {

        moveFrom = player->moveFrom();
        moveTo = player->moveTo();
	
    	if (!validMove(moveFrom, moveTo)) {
            throw InvalidMoveException();
        } else {
            if (moveCard(moveFrom, moveTo))
                throw TurnOverException();
        }

    } catch (InvalidMoveException & e) {

        cout << e.what() << endl;
        promptMove();

    } catch (TurnOverException & e) {

        cout << player->getName() << ": " << e.what() << endl;
        this->turn++;

    }

}

bool Game::validMove (char moveFrom, char moveTo) const {

    /* Declaring/Initializing local variables for more legible code. */    
    Player * curr = this->players[turn % players.size()];
    Hand * hand = curr->getHand();
    StockPile * stock = curr->getStockPile();
    DiscardPile * discards[4]; 
    BuildPile * builds[4];

    int indexTo = moveTo - 'a';
    
    /* Initializing some local variables. */
    for (int i = 0; i < 4; i++) {
        discards[i] = curr->getDiscardPiles()[i];
        builds[i] = this->buildPiles[i];
    }

    /* Moving fromt a player's stock pile. */
    if (moveFrom == '0') {
	
        if (indexTo >= 4 || indexTo < 0)
            return false;
	
        Card * cardFrom = stock->top();
	Card * cardTo;
	
	if ((cardFrom->getVal() == 0 || cardFrom->getVal() == 1) && builds[indexTo]->getSize() == 0) 
	  return true;

	if (builds[indexTo]->getSize() > 0)
	  cardTo = builds[indexTo]->top();
	else
	  return false;

        if (cardFrom->getVal() == 0) 
            return true;
        
        if (cardTo->getVal() == 0 && cardFrom->getVal()-1 == builds[indexTo]->getSize()) 
            return true;

	if (cardTo->getVal() != 0 && cardFrom->getVal()-1 == builds[indexTo]->getSize())
	  return true;
    } 

    /* Moving from player's hand. */
    else if (moveFrom > '0' && moveFrom < '6') {
          
        int indexFrom = moveFrom - '1';    

        if (moveTo >= '6' && moveTo <= '9')
            return true;
	
        if (indexFrom >= 5 || indexFrom < 0 || indexTo >= 4 || indexTo < 0)
            return false;	
	
        Card * cardFrom = hand->getCard(indexFrom);
	Card * cardTo;

	if ((cardFrom->getVal() == 0 || cardFrom->getVal() == 1) && builds[indexTo]->getSize() == 0) 
	  return true;

	if (builds[indexTo]->getSize() > 0)
	  cardTo = builds[indexTo]->top();
	else
	  return false;
	
        if (cardFrom->getVal() == 0)
            return true;	  
	
        if (cardTo->getVal() == 0 && cardFrom->getVal()-1 == builds[indexTo]->getSize()) 
            return true;	    

	if (cardTo->getVal() != 0 && cardFrom->getVal()-1 == builds[indexTo]->getSize())
	   return true;
    } 

    /* Moving from a plyer's discard pile. */
    else if (moveFrom > '5' && moveFrom <= '9') {

        int indexFrom = moveFrom - '6';
	
    	if (indexFrom >=4 || indexFrom < 0 || indexTo >= 4 || indexTo < 0)
            return false;
	
        Card * cardFrom = discards[indexFrom]->top();
        Card * cardTo;
	
	
	if ((cardFrom->getVal() == 0 || cardFrom->getVal() == 1) && builds[indexTo]->getSize() == 0) 
	  return true;

	if (builds[indexTo]->getSize() > 0)
	  cardTo = builds[indexTo]->top();
	else
	  return false;
        
        if (cardFrom->getVal() == 0) 
            return true;
	  
        if (cardTo->getVal() == 0 && cardFrom->getVal()-1 == builds[indexTo]->getSize()) 
            return true;

	if (cardTo->getVal() != 0 && cardFrom->getVal()-1 == builds[indexTo]->getSize())
	  return true;   
    }
    return false;
}

/** Makes the move - only is called is the move is valid. */
bool Game::moveCard(char moveFrom, char moveTo) {

    Player * curr = this->players[this->turn % this->players.size()];
    Card * card;

    /* Move from stock pile. */
    if (moveFrom == '0') {
        card = curr->removeFromStockPile();
        buildPiles[moveTo-'a']->add(card);
    }

    /* Move from hand. */
    else if (moveFrom >= '1' && moveFrom <= '5') {
        if (moveTo >= '6' && moveTo <= '9') {
            card = curr->removeCardFromHand(moveFrom-'1');
            curr->getDiscardPiles()[moveTo-'6']->add(card);
        }
        else {
            card = curr->removeCardFromHand(moveFrom-'1');
            buildPiles[moveTo-'a']->add(card);
        }
        if (curr->getHand()->isEmpty()) {
            for (int a = 0; a < 5; a++) {
                curr->addCardToHand(this->drawPile->remove());
            }
        }
    }

    /* Move from discard pile. */
    else {
        card = curr->getDiscardPiles()[moveFrom-'6']->remove();
        buildPiles[moveTo-'a']->add(card);
    }

    cout << curr->getName() << " moved " << card->getVal() << " from pile " << moveFrom << " to " << moveTo << "." << endl;

    /* Card was moved to a discard pile. */
    if (moveTo >= '6' && moveTo <= '9')
        return true;

    /* Card was not moved to a discard pile. */
    return false;
}

bool Game::gameOver() {
    for (unsigned long i = 0; i < this->players.size(); i++) {
        if (this->players[i]->getStockPile()->isEmpty())
            return true;
    }
    return false;
}
