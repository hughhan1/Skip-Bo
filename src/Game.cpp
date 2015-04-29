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
}

Game::Game(FILE* file) {
    // TO DO
}

void Game::setPlayers() {
    
    int numPlayers;
    std::string name;
    int input;

    cout << "Please enter the number of players: ";
    cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        cout << "Please enter the name of Player " << i + 1 << ": ";
        cin >> name;
        cout << "If this player is a human enter 0. If this player is a computer enter 1." << std::endl;
        cin >> input;

    if (input == 0)
        addPlayer(new Human(name));
    else
        addPlayer(new Computer(name));
    }
}

void Game::dealCards() {

    int numPlayers = players.size();
    int num;
    
    //Adding shuffle func
    drawPile->shuffle();

    //prompting stockpile size
    cout<<"Initial Stock pile size: ";
    cin>>num;
    
    
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            players[i]->addCardToHand(drawPile->remove());
        }
	for(int j = 0; j < num; j++){
	  players[i]->addCardToStockPile(drawPile->remove());
	}
    }
    
    
    /**Testing Purpose
    for(int i = 0; i < numPlayers; i++){
      for(int j = 0; j < 5; j++){
	cout<<"Player "<<i<<" "<<endl;
	cout<<players[i]->getHand()->getCard(j)->getVal() << endl;
      }
    }
    cout<<endl;**/
}

void Game::play() {
    /*
    int size = this->players.size();
    int turn = 0;

    while (game is not over) {
        move(turn % size);
        turn++;
    }
    */
}

void Game::printView(int i) {
  stringstream lines[11];
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
  
    
    for (int a = 0; a < numPlayers; a++) {
        if (player != this->players[a]) {
            Player* p = this->players[a];
            lines[0] << p->getName() << "\t";
            lines[1] << "(" << p->getStockPile()->getSize() << ")\tDiscard\t";
            lines[2] << p->getStockPile()->top()->getVal() << "\t";
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
    lines[4] << "Build Piles:\t-\t-\t-\t-";

    for (int a = 0; a < 4; a++) {
        if (this->getBuildPiles(a)->
            isEmpty()) {
            lines[5] << "- ";
        } else {
            lines[5] << this->getBuildPiles(a)->top()->getVal();
        }
    }

    lines[6] << "";

    lines[7] << player->getName();

    lines[8] << "Hand\t\tDiscard Piles\t\tStock Pile";

    lines[9] << "[1] [2] [3] [4] [5]\t[6] [7] [8] [9]\t\t[0]";

    for (int i = 0; i < 5; i++) {
        if (player->getHand()->getCard(i) != nullptr) {
	  lines[10] << player->getHand()->getCard(i)->getVal()<<"   ";
        }
        else {
            lines[10] << "-  ";
        }
    }

    lines[10] <<"    ";
    
    for (int a = 0; a < 4; a++){
        if (!player->getDiscardPiles()[a]->isEmpty()) {
	  lines[10] << player->getDiscardPiles()[a]->top()->getVal()<<" ";
        } else {
            lines[10] << "-   ";
        }
    }

    lines[10] << "\t " << player->getStockPile()->top()->getVal() << "  (" << player->getStockPile()->getSize()<<")";
    
}

DrawPile* Game::getDrawPile() const {
    return this->drawPile;
}

BuildPile* Game::getBuildPiles(int i) const {
    return this->buildPiles[i];
}

/** Is the move under consideration valid? */
bool Game::validMove (char moveFrom, char moveTo) const {
    if (moveFrom < '0' || moveFrom > '9') {
        cout << "That is not a valid pile to move a card from.\n";
        return false;
    }
    else if (moveFrom == '0') {
        if (moveTo < 'a' || moveTo > 'd') {
            cout << "That is not a valid pile to move a card to from your stockpile.\n";
            return false;
        }
        if(players.at(turn)->getStockPile()->top()->getVal()==0){
            return true;
        }
        if(!(players.at(turn)->getStockPile()->top()->getVal()-1==buildPiles[moveTo-'a']->top()->getVal())){
            cout<<"You cannot put a "<<players.at(turn)->getStockPile()->top()->getVal()<<" on that build pile.\n";
            return false;
        }
    }
    else if (moveFrom > '0' && moveFrom < '6') {
        if (moveTo < '6' || (moveTo > '9' && moveTo < 'a') || moveTo > 'd') {
            cout << "That is not a valid pile to move a card to from your hand.\n";
            return false;
        }
        if(players.at(turn)->getHand()->getCard(moveFrom-'1')->getVal()==0){
            return true;
        }
        if(!(players.at(turn)->getHand()->getCard(moveFrom-'1')->getVal()-1==buildPiles[moveTo-'a']->top()->getVal())){
            cout<<"You cannot put a "<<players.at(turn)->getHand()->getCard(moveFrom-'1')->getVal()<<" on that build pile.\n";
            return false;
        }
    }
    else if (moveFrom > '5' && moveFrom < ':') {
        if (moveTo < 'a' || moveTo > 'd') {
            cout << "That is not a valid pile to move a card to from your discard piles.\n";
            return false;
        }
        if(players.at(turn)->getDiscardPiles()[moveFrom-'6']->top()->getVal()==0){
            return true;
        }
        if(players.at(turn)->getDiscardPiles()[moveFrom-'6']->top()->getVal()-1==buildPiles[moveTo-'a']->top()->getVal()){
            cout<<"You cannot put a "<<players.at(turn)->getDiscardPiles()[moveFrom-'6']->top()->getVal()<<" on that build pile.\n";
        }
    }
    return true;
}

/** Makes the move - only is called is the move is valid */
void Game::moveCard( char moveFrom, char moveTo) {
    if (moveFrom == '0') {
        //move from top of stockpile to the (moveTo-'a')th build pile
    }
    if (moveFrom > '0' && moveFrom < '6') {
        if (moveTo > '5' &&moveTo < ':') {
            //move from hand to top of the (moveTo-'6')th discard pile
        }
        else {
            //move from hand to top of the (moveTo-'a')th build pile
        }
    }
    if (moveFrom > '5') {
        //move from top of discard pile to the (moveTo-'a')th build pile
    }
}
