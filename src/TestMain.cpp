#include <iostream>
#include <cassert>
#include "DrawPile.h"
#include "Human.h"
#include "Computer.h"

using namespace std; // just for convenience while testing. 

int main() {
    cout << "Testing" << endl;
    Card* card;
    DrawPile* deck = new DrawPile();

    for (int i = 0; i < 162; i++) {
        card = deck->remove();
        cout << card->getVal() << endl;
    }

    Player* player1 = new Human("Human 1");
    Player* player2 = new Computer("Computer 1");

    cout << "Test End" << endl;
    return 0;
}
