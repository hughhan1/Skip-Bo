/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: TestMain.cpp
 */

#include <iostream>
#include "DrawPile.h"
#include "Human.h"
#include "Computer.h"
#include "Card.h"
#include "Hand.h"
#include "StockPile.h"
#include "BuildPile.h"
#include "Game.h"

#include <cassert>

using std::cout; 
using std::endl; 

class TestMain {
public:

  static void cardTest() {
    Card c1;
    assert(c1.getVal() == -1);
    Card c2(1);
    assert(c2.getVal() == 1);
    Card c3(1);
    assert(c2 == c3);
    assert(c1 < c2);
    assert(c2 > c1);
    assert(c1 != c2);
  }

  static void handTest() {
    Hand test;
    assert(test.isEmpty());
    Card* c = new Card(1);
    assert(test.add(c));
    assert(!test.isEmpty());
    assert(c == test.getCard(0));
    Card c1(2);
    assert(test.add(&c1));
    Card c2(3);
    assert(test.add(&c2));
    Card c3(4);
    assert(test.add(&c3));
    Card c4(5);
    assert(test.add(&c4));
    Card c5(6);
    assert(!test.add(&c5));
    assert(&c4 == test.getCard(4));
    assert(c == test.remove(0));
    assert(&c1 == test.remove(1));
    assert(&c2 == test.remove(2));
    assert(&c3 == test.remove(3));
    assert(&c4 == test.remove(4));
    assert(test.getCard(0) == nullptr);
  }

  static void drawPileTest() {
    DrawPile test;
    Card* c;
    assert(test.getSize() == 162);
    assert(!test.isEmpty());

    for (int i = 0; i < 18; i++) {
      assert(test.getSize() + i == 162);
      c = test.remove();
      assert (c->getVal() == 0);
    }


    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 12; j++) {
	c = test.remove();
	assert(c->getVal() == 12-i);
      }
    }

    assert(test.isEmpty());

    c = new Card(11);
    Card* d = new Card(9);
    assert(test.add(c));
    assert(test.getSize() == 1);
    assert(!test.isEmpty());
    assert(test.add(d));
    assert(test.getSize() == 2);
    assert(test.remove()->getVal() == 11);
    assert(test.getSize() == 1);
    assert(test.remove()->getVal() == 9);
    assert(test.getSize() == 0);
    assert(test.isEmpty());
  }

  static void stockPileTest() {
    StockPile test;
    Card* c;

    assert(test.getSize() == 0);
    assert(test.isEmpty());

    Card c0(1);
    assert(test.add(&c0));
    assert(test.top()->getVal() == c0.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 1);

    Card c1(2);
    assert(test.add(&c1));
    assert(test.top()->getVal() == c1.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 2);

    Card c2(10);
    assert(test.add(&c2));
    assert(test.top()->getVal() == c2.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 3);

    c = test.remove();
    assert(c->getVal() == c2.getVal());
    assert(test.top()->getVal() == c1.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 2);

    c = test.remove();
    assert(c->getVal() == c1.getVal());
    assert(test.top()->getVal() == c0.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 1);

    c = test.remove();
    assert(c->getVal() == c0.getVal());
    assert(test.isEmpty());
    assert(test.getSize() == 0);
  }

  static void buildPileTest() {
    BuildPile test;
    Card* c;

    assert(test.getSize() == 0);
    assert(test.isEmpty());

    Card c0(1);
    assert(test.add(&c0));
    assert(test.top()->getVal() == c0.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 1);

    Card c1(2);
    assert(test.add(&c1));
    assert(test.top()->getVal() == c1.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 2);

    Card c2(10);
    assert(test.add(&c2));
    assert(test.top()->getVal() == c2.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 3);

    c = test.remove();
    assert(c->getVal() == c2.getVal());
    assert(test.top()->getVal() == c1.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 2);

    c = test.remove();
    assert(c->getVal() == c1.getVal());
    assert(test.top()->getVal() == c0.getVal());
    assert(!test.isEmpty());
    assert(test.getSize() == 1);

    c = test.remove();
    assert(c->getVal() == c0.getVal());
    assert(test.isEmpty());
    assert(test.getSize() == 0);
  }

  /*These need to be written still
  static void humanTest() {
    Player * player1 = new Human("human1");
    assert(player1->getName() == "human1");

    // const Hand * h = player1->getHand();
    for(int i = 0; i < 5; i++) {
      //assert(h[i] == nullptr);                                              
    }
  }

  static void computerTest() {

  }*/

  static void gameMoveTest() {
    Game test;
    Human * p1 = new Human("testp1");
    Human * p2 = new Human("testp2");
    
    test.addPlayer(p1);
    test.addPlayer(p2);
    test.dealCards(3);
    // test.printView(0); // To help understand these tests


    // Can't move from Build Piles to other Piles
    assert(!test.validMove('a', 'b'));
    assert(!test.validMove('b', '1'));
    assert(!test.validMove('c', '6'));
    assert(!test.validMove('d', '0'));

    // Can't move from Hand or Discard Pile to Stock Pile
    assert(!test.validMove('1', '0'));
    assert(!test.validMove('6', '0'));

    // Can't move from Stock Pile to Hand or Discard Piles
    assert(!test.validMove('0', '2'));
    assert(!test.validMove('0', '7'));

    assert(test.validMove('1', 'a')); // Hand to new build pile
    test.moveCard('1', 'a');
    assert(test.buildPiles[0]->top()->getVal() == 0);
    assert(test.buildPiles[0]->getSize() == 1);
    
    assert(test.validMove('0', 'a')); // Stock Pile to old build pile
    test.moveCard('0', 'a');
    assert(test.buildPiles[0]->top()->getVal() == 0);
    assert(test.buildPiles[0]->getSize() == 2);

    assert(test.validMove('0', 'b')); // Stock Pile to new build pile
    test.moveCard('0','b');
    assert(test.buildPiles[1]->top()->getVal() == 0);
    assert(test.buildPiles[1]->getSize() == 1);

    assert(test.validMove('5', '8')); // Hand to Discard Pile (turn over)
    test.moveCard('5', '8');
    assert(test.players[0]->getDiscardPiles()[2]->top()->getVal() == 0);
    assert(test.players[0]->getDiscardPiles()[2]->getSize() == 1);
  }
};

int main() {
  
  cout << "Testing." << endl;
  TestMain::cardTest();
  cout << "Card Tests passed." << endl;
  TestMain::handTest();
  cout << "Hand Tests passed." << endl;
  TestMain::drawPileTest();
  cout << "Draw Pile Tests passed." << endl;
  TestMain::stockPileTest();
  cout << "Stock Pile Tests passed." << endl;
  TestMain::buildPileTest();
  cout << "Build Pile Tests passed." << endl;
  // TestMain::humanTest();
  // cout << "Human Tests passed." << endl;
  // TestMain::computerTest();
  // cout << "Computer Tests passed." << endl;
  TestMain::gameMoveTest();
  cout << "Game Move Tests passed." << endl;
  
  return 0;
}
