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
#include "Game.h"


Game::Game() { 
    this->drawPile = new DrawPile();
    for (int i = 0; i < 4; i++) {
        this->buildPiles[i] = new BuildPile();
    }
}

Game::Game(FILE* file) {
    // TO DO
}

void Game::makeMove(int i) {
    Player player = *(this->players[i]);
}

void Game::addPlayer(Player* player){
    players.push_back(player);
}

void Game::setPlayers() {
    
    int numOfPlayers;
    std::string name;
    int input;

    std::cout << "Please enter the number of players: ";
    std::cin >> numOfPlayers;

    for (int i = 0; i < numOfPlayers; i++) {
        std::cout << "Please enter the name of the player " << i + 1 <<": ";
        std::cin >> name;
        std::cout << "If this player is a human enter 0. If this player is a computer enter 1" << std::endl;
        std::cin >> input;

    if (input == 0)
        addPlayer(new Human(name));
    else
        addPlayer(new Computer(name));

    }
}

void Game::dealCards() {

    int numPlayers = this->players.size();

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            this->players[i]->getHand()->add(this->drawPile->remove());
        }
    }
}

void Game::startGame() {
    // TO DO
}

void Game::loadGame() {
    // TO DO
}

void Game::saveGame() {
    // TO DO
}

void Game::endGame() {
    // TO DO
}

void Game::printView(int i) {
  
 /* 
    std::string playernames;
    std::string pileinfos;
    std::string otherscards;
    for (int a = 0; a < this->players.length; a++) {
        Add next player's name to playernames (with appropriate spacing)
        Add size of next player's stockpile to pileinfos
        pileinfos+="\tDiscard\t\t";
        Add next player's visible cards to otherscards (with appropriate spacing)
    }
    std::cout<<"\n";
    std::cout<<"\t\t[a]\t[b]\t[c]\t[d]\n";
    std::cout<<"Build Piles\t";
    List build piles' top cards (with proper spacing)
*/

  /*    Player player = *(this->players[i]);

    std::cout << std::endl;
    std::cout << player.name() << std::endl;
    std::cout << "Hand\t\t\tDiscard Piles\t\tStockpile" << std::endl;
    std::cout << "[1] [2] [3] [4] [5]\t[6] [7] [8] [9]\t\t[0]" << std::endl;

    for (int a = 0; a < 5; a++) {
        std::cout << " ";
        if (player.hand().getCard(a).getNum() != -1) {
            std::cout << player.hand().getCard(a);
        }
        else {
            std::cout << "-  ";
        }
    }

    std::cout << "\t";

    for (int a = 0; a < 4; a++){
        std::cout << " ";
        if (discardPiles[a].top().getNum() != -1){
            std::cout << discardPiles[a].top.getNum();
        } else {
            std::cout << "-  ";
        }
    }

    std::cout << "\t " << stockPile.top().getNum() << "  ";
    std::cout << player.getStockPile().getSize();
    std::cout << std::endl;
  */
}
