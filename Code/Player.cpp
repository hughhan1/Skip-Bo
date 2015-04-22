/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Player.cpp
 */

#include <iostream>
#include "Player.h"

Player::Player(std::string name) {
    this->name = name;
    this->hand = new Hand();
    for (int a = 0; a < 4; a++) {
        discardPiles[a] = new DiscardPile();
    }
    stockPile = new StockPile();
    isTurn = false;
}
void Player::printView() {
    std::string playernames;
    std::string pileinfos;
    std::string otherscards;
    //for(int a=0;a<number of players;a++){
    //Add next player's name to playernames (with appropriate spacing)
    //Add size of next player's stockpile to pileinfos
    //pileinfos+="\tDiscard\t\t";
    //Add next player's visible cards to otherscards (with appropriate spacing)
    //}
    //std::cout<<"\n";
    //std::cout<<"\t\t[a]\t[b]\t[c]\t[d]\n";
    //std::cout<<"Build Piles\t";
    //List build piles' top cards (with proper spacing)
    std::cout << std::endl;
    std::cout << this->name << std::endl;
    std::cout << "Hand\t\t\tDiscard Piles\t\tStockpile" << std::endl;
    std::cout <<"[1] [2] [3] [4] [5]\t[6] [7] [8] [9]\t\t[0]" << std::endl;
    for (int a = 0; a < 5; a++) {
        std::cout << " ";
        if (this->hand.getCard(a) != nullptr) {
            //print ath card in hand (with proper spacing)
        }
        else{
            std::cout<<"-  ";
        }
    }
    std::cout << "\t";
    for (int a = 0; a < 4; a++){
        std::cout << " ";
        if (discardPiles[a].top().getNum() == -1){
            //print top card of ath discard pile (with proper spacing)
        }
    }
    std::cout <<"\t "<< stockPile.top().getNum() << "  ";
    //print size of stockpile
    std::cout << std::endl;
}