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

    int numPlayers = this->players.size();

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            this->players[i]->addCardToHand(this->drawPile->remove());
        }
    }
}

void Game::play() {
    int size = this->players.size();
    int turn = 0;

    // while the game is not over
    move(turn % size);
}

void Game::printView(int i) {
    stringstream* s = generateView(i);
    for (int a = 0; a < 11; a++) {
        cout << s[a].str() << endl;
    }    
}

/** Private */

void Game::addPlayer(Player* player){
    players.push_back(player);
}

stringstream* Game::generateView(int i) {
    Player * player = this->players[i];
    int numPlayers = this->players.size();
  
    /* An array of 11 lines that will be generated. */
    stringstream lines[11];

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
        if (this->getBuildPiles()[a]->
            isEmpty()) {
            lines[5] << "- ";
        } else {
            lines[5] << this->getBuildPiles()[a]->top()->getVal();
        }
    }

    lines[6] << "";

    lines[7] << player->getName();

    lines[8] << "Hand\t\tDiscard Piles\t\tStock Pile";

    lines[9] << "[1] [2] [3] [4] [5]\t[6] [7] [8] [9]\t\t[0]";

    for (int a = 0; a < 5; a++) {
        if (player->getHand()->getCard(i) != nullptr) {
            lines[10] << player->getHand()->getCard(i)->getVal();
        }
        else {
            lines[10] << "-  ";
        }
    }
    
    for (int a = 0; a < 4; a++){
        if (player->getDiscardPiles()[a]->isEmpty()) {
            lines[10] << player->getDiscardPiles()[a]->top()->getval();
        } else {
            lines[10] << "-  ";
        }
    }

    lines[10] << "\t " << player->getStockPile()->top()->getVal() << "  " << player->getStockPile()->getSize();

    return lines;
}

const DrawPile* Game::getDrawPile() const {
    const DrawPile* d = this->drawPile;
    return d;
}

const BuildPile** Game::getBuildPiles() const {
    const BuildPile** b = this->buildPiles;
    return b;
}

void Game::move(int i) {
    Player* player = this->players[i];
    if (Human* h = dynamic_cast<Human*>(player)) {
        printView(i);
        cout << "Enter "; 
    } else {

    }
}
