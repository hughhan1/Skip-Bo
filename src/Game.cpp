/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Game.cpp
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include "Game.h"

using std::string;
using std::to_string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/** Public */

Game::Game() { 
    this->drawPile = new DrawPile();
    for (int i = 0; i < 4; i++) {
        this->buildPiles[i] = new TopPile();
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
	
        cout << "Enter 0 if this player is a human, and 1 if this player is a computer: ";
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

    Player * curr = nullptr;
    int numPlayers = this->players.size();
    char input = '0';

    int t = this->turn;

    while (!gameOver() && input != 'q') {

        curr = this->players[this->turn % numPlayers];

        cout << curr->getName() << "'s turn!" << endl << endl;

        if (dynamic_cast<Human*>(curr)) {
            cout << "Enter any character to start your turn, or q to quit the game: ";
            cin >> input;
        }

        if (input != 'q') {

            while (t == this->turn) {
                printView(this->turn % numPlayers);
                promptMove();
            }

            t++;

        } else {
            cout << endl << "Would you like to save the game (y/n)? ";
            cin >> input;

            if (input == 'y' || input == 'Y')
                saveGame();

            cout << endl << "Goodbye!" << endl;
            input = 'q';
        }

        cout << "DRAWPILE SIZE: " << this->drawPile->getSize() << endl;
    }
}
  
void Game::printView(int i) {
    stringstream lines[11];
    generateView(lines, i);
    cout << endl;
    for (int a = 0; a < 11; a++) {
        cout << lines[a].str() << endl;
    }
}


/** Private */

void Game::addPlayer(Player* player){
    players.push_back(player);
}

void Game::generateView(stringstream *lines, int i){
    Player * player = this->players[i];
    int numPlayers = this->players.size();
    int value;
    
    for (int a = 0; a < numPlayers; a++) {
        if (player != this->players[a]) {
            Player* p = this->players[a];
            for(int i=0;i<50;i++){ //clears the screen (so you can't see anything but your turn)
                lines[0] << endl;
            }
            lines[0] <<"************************************************************" << endl;
            lines[0] << p->getName() << "\t\t\t";
            lines[1] << "(" << p->getStockPile()->getSize() << ")\t  Discard\t\t";
            
            value = p->getStockPile()->top()->getVal();
            if (value < 10)
                lines[2] << " ";
            lines[2] << p->getStockPile()->top()->getVal() << " \t ";
            
            for (int b = 0; b < 4; b++) {
                if (p->getDiscardPiles()[b]->isEmpty()) {
                    lines[2] << "-  ";
                } else {
                    lines[2] << p->getDiscardPiles()[b]->top()->getVal()<<" ";
                    if(p->getDiscardPiles()[b]->top()->getVal()<10){
                        lines[2] << " ";
                    }
                }
            }
            lines[2] << "\t\t";
        }
    }
    
    lines[3] << "";
    lines[4] << "Build Piles:\t[a]\t[b]\t[c]\t[d]";
    
    lines[5] << "\t\t";
    for (int a = 0; a < 4; a++) {
        if (this->buildPiles[a]->isEmpty())
            lines[5] << " - ";
        else{
            if(this->buildPiles[a]->getSize()<10)
                lines[5] << " ";
            lines[5] << this->buildPiles[a]->getSize() << " ";
        }
        lines[5] << "\t";
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
            lines[10] << " -  ";
        }
    }
    
    lines[10] << "\t";
    for (int a = 0; a < 4; a++){
        if (!player->getDiscardPiles()[a]->isEmpty()) {
            if(player->getDiscardPiles()[a]->top()->getVal()<10)
                lines[10] << " ";
            lines[10] << player->getDiscardPiles()[a]->top()->getVal() << "  ";
        }
        else {
            lines[10] << " -  ";
        }
    }
    
    lines[10] << "\t " << player->getStockPile()->top()->getVal() << "  (" << player->getStockPile()->getSize() << ")" << endl << endl;
    lines[10] << "************************************************************" << endl;
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

        if (dynamic_cast<Human*>(player)) {
            cout << e.what() << endl;
            printView(this->turn % players.size());
            cout << endl;
        }
        promptMove();

    } catch (TurnOverException & e) {

        cout << player->getName() << ": " << e.what() << endl;
        fillHand(this->turn % players.size());
        this->turn++;

    }

}

bool Game::validMove (char moveFrom, char moveTo) const {

    /* Declaring/Initializing local variables for more legible code. */    
    Player * curr = this->players[turn % players.size()];
    Hand * hand = curr->getHand();
    TopPile * stock = curr->getStockPile();
    TopPile * discards[4]; 
    TopPile * builds[4];

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

        Card * cardFrom = hand->getCard(indexFrom);
        if(cardFrom==nullptr)
            return false;
        
        if (moveTo >= '6' && moveTo <= '9')
            return true;
	
        if (indexFrom >= 5 || indexFrom < 0 || indexTo >= 4 || indexTo < 0)
            return false;	
	
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
        
        Card * cardFrom = discards[indexFrom]->top();
        if(cardFrom == nullptr)
            return false;
        
    	if (indexFrom >= 4 || indexFrom < 0 || indexTo >= 4 || indexTo < 0)
            return false;
	
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

    endMove();

    /* Card was moved to a discard pile. */
    if (moveTo >= '6' && moveTo <= '9')
        return true;

    /* Card was not moved to a discard pile. */
    return false;
}

void Game::fillHand(int i) {
    Player * curr = this->players[i];
    Hand * hand = curr->getHand();
    while (!hand->isFull()) {
        curr->addCardToHand(this->drawPile->remove());
    }
}

void Game::endMove() {
  for (int i = 0; i < 4; i++) {
    if (this->buildPiles[i]->getSize() == 12) {
      addToDrawPile(i);
    }
  }
}

void Game::addToDrawPile(int index) {

    TopPile * b = this->buildPiles[index];
  b->shuffle();
  while (!b->isEmpty()) {
    this->drawPile->add(b->remove());
  }
}

bool Game::gameOver() {
    for (unsigned long i = 0; i < this->players.size(); i++) {
        if (this->players[i]->getStockPile()->isEmpty())
            return true;
    }
    return false;
}

void Game::saveGame() {
  vector<string> data;
  Player * player;
  string s;
  Card * card;

  //drawPile data
  s += to_string(drawPile->getSize());
  s += " ";
  while(!drawPile->isEmpty()){
    card = drawPile->remove();
    s += to_string(card->getVal());
    s += " ";   
  }

  //buildPile data
  for(int i = 0; i < 4; i++){
    s += to_string(buildPiles[i]->getSize());
    s += " ";
    while(!buildPiles[i]->isEmpty()){
      card = buildPiles[i]->remove();
      s += to_string(card->getVal());
      s += " ";
    }
  }

  data.push_back(s);
  s.clear();

  //Players data   if card == nullptr, using -1
  s += to_string((int)players.size());
  s += " ";
  for(int i = 0; i < (int)players.size(); i++){
    player = players[i];
    s += player->getName();
    s += " ";
    //hand data
    for(int j = 0; j < 5; j++){
      card = player->removeCardFromHand(j);

      if(card == nullptr){
	s += to_string(-1);
        s += " "; 
      }
      else{
	s += to_string(card->getVal());
        s += " ";
      }
    }

    //discardPile data
    for(int j = 0; j < 4; j++){
      s += to_string(player->getDiscardPiles()[j]->getSize());
      s += " ";
      while(!player->getDiscardPiles()[j]->isEmpty()){
	card = player->getDiscardPiles()[j]->remove();
	s += card->getVal();
	s += " ";
      }
    }

    //stockPile data
    s += to_string(player->getStockPile()->getSize());
    s += " ";
    while(!player->getStockPile()->isEmpty()){
      card = player->getStockPile()->remove();
      s += card->getVal();
      s += " ";
    }

    data.push_back(s);
    s.clear();
  }

  cout<<"Save File name: ";
  cin >> s;
  cout<<endl;

  std::ofstream output(s, std::ios::out);

  for(auto it = data.begin(); it != data.end(); it++){
    output<<*it;
  }

  output.close();
  cout<<"Game saved"<<endl;
}
