/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Game.cpp
 */

#include <cstdio>
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

Game::~Game(){

    delete drawPile;

    for (int i = 0; i < 4; i++) {
        delete buildPiles[i];
    }

    int numPlayers = this->players.size();
    for (int i = 0; i < numPlayers; i++) {
        delete this->players[i];
    }

/*
    while(!drawPile->isEmpty()){
        card = drawPile->remove();
        delete card;      
    }

    delete drawPile;

    for (int i = 0; i < 4; i++) {
        while(!buildPiles[i]->isEmpty()) {
            card = buildPiles[i]->remove();
            delete card;
        }
        delete buildPiles[i];
    }

    for (int i = 0; i < (int)players.size(); i++) {
        for (int j = 0; j < 4; j++) {
            while(!players[i]->getDiscardPiles()[j]->isEmpty()) {
                card = players[i]->getDiscardPiles()[j]->remove();
                delete card;
            }
        }

        while(!players[i]->getStockPile()->isEmpty()) {
            card = players[i]->getStockPile()->remove();
            delete card;
        }
    }

    int numPlayers = this->players.size();
    for (int i = 0; i < numPlayers; i++) {
        delete this->players[i];
    }
*/
}


Game::Game(std::ifstream &inFile) {
  string str;
  int num = 0;
  int val = 0;
  int val2 = 0;

  drawPile = new DrawPile();

  for(int i = 0; i < 4; i++){
    buildPiles[i] = new TopPile();
  }
 
  //drawPile data
  while(!drawPile->isEmpty()){
    drawPile->remove();      
  }

  getline(inFile, str);
  num = stoi(str);
  
  for(int i = 0; i < num; i++){
    getline(inFile, str);
    val = stoi(str);
    Card * card = new Card(val);
    drawPile->add(card);      
  }
   
  //buildPile data
  for(int i = 0; i < 4; i++){
    getline(inFile, str);
    num = stoi(str);

    for(int j = 0; j < num; j++){
      getline(inFile, str);
      val = stoi(str);
      Card * card = new Card(val);
      buildPiles[i]->add(card);
    }
  }

  //players data
  getline(inFile, str);
  num = stoi(str);

  for(int i = 0; i < num; i++){
    getline(inFile, str);
    val = stoi(str);

    if(val == 0){
      getline(inFile, str);
      addPlayer(new Computer(str));
          
    }
    else{
      getline(inFile, str);
      addPlayer(new Human(str));
          
    }
    //hand data
    for(int j = 0; j < 5; j++){
      getline(inFile, str);
      val = stoi(str);

      if(val == -1){
	players[i]->addCardToHand(nullptr);
	      
      }
      else{
	Card * card = new Card(val);
	players[i]->addCardToHand(card);	      
      }
    }

    //discardPile data
    for(int j = 0; j < 4; j++){
      getline(inFile, str);
      val = stoi(str);

      for(int k = 0; k < val; k++){
	getline(inFile, str);
	val2 = stoi(str);
	Card * card = new Card(val2);
	players[i]->getDiscardPiles()[j]->add(card);	      
      }
    }

    getline(inFile, str);
    val = stoi(str);

    for(int j = 0; j < val; j++){
      getline(inFile, str);
      val2 = stoi(str);
      Card * card = new Card(val2);
      players[i]->getStockPile()->add(card);
    }
  }

  getline(inFile, str);
  num = stoi(str);
  turn = num;
}

int Game::setPlayers() {

  int numPlayers = -1;
  std::string name;
  int input;
  int num = -1;
  bool go = false;

  while (!(numPlayers >= 2 && numPlayers <= 6)) {
    cout << "Please enter the number of players: ";
    cin >> numPlayers;
    cout << endl;

    if (numPlayers < 2 || numPlayers > 6)
      cout << "Skip-bo is played with at least 2 players, and at most 6 players." << endl << endl;

  }

  for (int i = 0; i < numPlayers; i++) {
    cout << "Please enter the name of Player " << i + 1 << ": ";

    getchar();
    std::getline(cin, name);
    //cin >> name;

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
  while(!go) {
    cout << "Please enter the initial stock pile size: ";
    cin >> num;
    cout << endl;

    if (num < 1) {
      cout << "You can't play with less than 1 card!" << endl << endl;
      go = false;
    } else if (numPlayers < 5 && num > 30) {
      cout << "The card limit for 2-4 players is 30." << endl << endl;
      go = false;
    } else if (numPlayers >= 5 && num > 20 ) {
      cout << "The card limit for 2-6 players is 20." << endl << endl;
      go = false;
    } else
      go = true;

  }
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

            while (!gameOver() && t == this->turn) {
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
            return;
        }
    }

    if (gameOver()) {
        cout << "Congratulations! " << curr->getName() << " is the winner!" << endl; 
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

void Game::generateView(stringstream *lines, int i) {
    Player * player = this->players[i];
    int numPlayers = this->players.size();
    int value;

    for (int i = 0; i < numPlayers; i++) {
        lines[0] << "***********************";
    }

    lines[0] << endl;
    
    for (int a = 0; a < numPlayers; a++) {
        if (player != this->players[a]) {
            Player* p = this->players[a];

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
    
    for (int i = 0; i < numPlayers; i++) {
        lines[10] << "-----------------------";
    }

    lines[10] << endl;
}


void Game::promptMove() {

    Player * player = players[this->turn % players.size()];

    char moveFrom;
    char moveTo;

    try {

        /* To make the computer smarter, we let it see the build piles. */
        if (Computer* computer = dynamic_cast<Computer*>(player))
            computer->importChoices(this->buildPiles);

        moveFrom = player->moveFrom();
        moveTo = player->moveTo();
    
        /* Check if the move is valid. */
        if (!validMove(moveFrom, moveTo)) {
            throw InvalidMoveException();
        } else {
            if (moveCard(moveFrom, moveTo))
                throw TurnOverException();
        }

    } catch (InvalidMoveException & e) {

        /* Only print error message if the player is a human. */
        if (dynamic_cast<Human*>(player)) {
            cout << e.what() << endl;
            printView(this->turn % players.size());
            cout << endl;
        }
        promptMove();

    } catch (TurnOverException & e) {

        /* Fill player's hand and increment turn counter at the end of each turn. */
      cout << player->getName() << ": " << e.what() << endl << endl;
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

    int numPlayers = this->turn % this->players.size();
    Player * curr = this->players[numPlayers];
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
        } else {
            card = curr->removeCardFromHand(moveFrom-'1');
            buildPiles[moveTo-'a']->add(card);
        }
        if (curr->getHand()->isEmpty()) {
            fillHand(numPlayers);
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
        if (this->drawPile->isEmpty()) {
            delete this->drawPile;
            this->drawPile = new DrawPile();
            this->drawPile->shuffle();
        }
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
  s += "\n";
  while(!drawPile->isEmpty()){
    card = drawPile->remove();
    s += to_string(card->getVal());
    s += "\n";   
  }

  //buildPile data
  for(int i = 0; i < 4; i++){
    s += to_string(buildPiles[i]->getSize());
    s += "\n";
    while(!buildPiles[i]->isEmpty()){
      card = buildPiles[i]->remove();
      s += to_string(card->getVal());
      s += "\n";
    }
  }

  data.push_back(s);
  s.clear();

  //Players data   if card == nullptr, using -1
  s += to_string((int)players.size());
  s += "\n";
  for (int i = 0; i < (int)players.size(); i++) {
    if (dynamic_cast<Human*>(players[i]) == nullptr) {
      s += "0";
      s += "\n";
    }
    else{
      s += "1";
      s += "\n";
    }
    
    player = players[i];
    s += player->getName();
    s += "\n";

    //hand data
    for(int j = 0; j < 5; j++){
      card = player->removeCardFromHand(j);

      if(card == nullptr){
	s += to_string(-1);
        s += "\n"; 
      }
      else{
	s += to_string(card->getVal());
        s += "\n";
      }
    }

    //discardPile data
    for(int j = 0; j < 4; j++){
      s += to_string(player->getDiscardPiles()[j]->getSize());
      s += "\n";
      while(!player->getDiscardPiles()[j]->isEmpty()){
	card = player->getDiscardPiles()[j]->remove();
	s += to_string(card->getVal());
	s += "\n";
      }
    }

    //stockPile data
    s += to_string(player->getStockPile()->getSize());
    s += "\n";
    while(!player->getStockPile()->isEmpty()){
      card = player->getStockPile()->remove();
      s += to_string(card->getVal());
      s += "\n";
    }

    data.push_back(s);
    s.clear();
  }

  s += to_string(turn);
  data.push_back(s);

  s.clear();
  
  cout << "Save File name: ";
  cin >> s;
  cout << endl;

  std::ofstream output(s, std::ios::out);

  for (auto it = data.begin(); it != data.end(); it++) {
    output<<*it;
  }

  output.close();
  cout<<"Game saved"<<endl;
}
