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

Game::Game() { 
    this->drawPile = new DrawPile();
    for (int i = 0; i < 4; i++) {
        this->buildPiles[i] = new BuildPile();
    }
}

Game::Game(FILE* file) {
    // TO DO
}

void Game::play() {
	int size = this->players.size();
	int turn = 0;

	// while the game is not over
	move(turn % size);
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
        std::cout << "Please enter the name of Player " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "If this player is a human enter 0. If this player is a computer enter 1." << std::endl;
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

void Game::printView(int i) {
  
    Player * player = this->players[i];
    int numPlayers = this->players.size();
  
    /** An array of 11 lines that will be printed to the screen. */
    stringstream lines[11];

    for (int a = 0; a < numPlayers; a++) {
        if (player != this->players[a]) {
            Player* p = this->players[a];
            lines[0] << p->getName() << "\t";
            lines[1] << "(" << p->getStockPile()->getSize() << ")\tDiscard\t";
            lines[2] << p->getStockPile()->top()->getVal() << "\t";
            for (int b = 0; b < 4; b++) {
                if (p->getDiscardPile()[b]->isEmpty()) {
                    lines[2] << "- ";
                } else {
                    lines[2] << p->getDiscardPiles()[b]->top()->getVal();
                }
            }
            lines[2] << "\t";
        } 
    }

    lines[3] << "";
    lines[4] << "Build Piles:\t-\t-\t-\t-"

    for (int a = 0; a < 4; a++) {
        if (this->getBuildPiles()[a].isEmpty()) {
            lines[5] << "- ";
        } else {
            lines[5] << this->getBuildPiles()[a]->top()->getVal();
        }
    }

    lines[6] << "";

    std::cout<<"\n";
    std::cout<<"\t\t[a]\t[b]\t[c]\t[d]\n";
    std::cout<<"Build Piles\t";
    List build piles' top cards (with proper spacing)

    std::cout << std::endl;
    std::cout << player->getName() << std::endl;
    std::cout << "Hand\t\t\tDiscard Piles\t\tStockpile" << std::endl;
    std::cout << "[1] [2] [3] [4] [5]\t[6] [7] [8] [9]\t\t[0]" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << " ";
        if (player->getHand()->getCard(i) != nullptr) {
			std::cout << player->getHand()->getCard(i)->getVal();
        }
        else {
            std::cout << "-  ";
        }
    }

    std::cout << "\t";
    /*
    for (int i = 0; i < 4; a++){
        std::cout << " ";
        if (discardPiles[i]->top().getVal() != -1){
            std::cout << discardPiles[i]->top.getval();
        } else {
            std::cout << "-  ";
        }
    }

    std::cout << "\t " << stockPile.top()->getVal() << "  ";
    std::cout << player.getStockPile().getSize();
    std::cout << std::endl;
    */
}

void Game::move(int i) {
	Player* player = this->players[i];
	if (Human* h = dynamic_cast<Human*>(player)) {
		printView(i);
        std::cout << "Enter "
	} else {

	}
}
