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

    // Testing Card (testing getVal(), and the overloaded operators)
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

    // Testing Hand
    static void handTest() {
        Hand test;

        // Should be empty at start
        assert(test.isEmpty());

        // Testing add(), isEmpty()
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

        // Can't add a 6th card to the hand
        Card c5(6);
        assert(!test.add(&c5));

        assert(&c4 == test.getCard(4));

        // Testing remove()
        assert(c == test.remove(0));
        assert(&c1 == test.remove(1));
        assert(&c2 == test.remove(2));
        assert(&c3 == test.remove(3));
        assert(&c4 == test.remove(4));

        assert(test.getCard(0) == nullptr);
    }

    // Testing drawPile
    static void drawPileTest() {
        DrawPile test;
        Card* c;

        // Testing constructor, getSize(), isEmpty()
        assert(test.getSize() == 162);
        assert(!test.isEmpty());

        // Removing all skip bo cards (testing remove())
        for (int i = 0; i < 18; i++) {
            assert(test.getSize() + i == 162);
            c = test.remove();
            assert (c->getVal() == 0);
        }

        // Removing the rest of the cards (testing remove())
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                c = test.remove();
                assert(c->getVal() == 12-i);
            }
        }

        assert(test.isEmpty());

        // Testing add()
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

    // Testing stockPile
    static void stockPileTest() {
        StockPile test;
        Card* c;

        // Testing constructor, getSize(), isEmpty()
        assert(test.getSize() == 0);
        assert(test.isEmpty());

        // Testing add(...), getSize(), isEmpty(), and top()
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

        // Testing remove(), getSize(), isEmpty(), and top()
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

    // Testing buildPile (same as stockPile basically)
    static void buildPileTest() {
        BuildPile test;
        Card* c;

        // Testing constructor, getSize(), isEmpty()
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

        // Testing remove(), getSize(), isEmpty(), and top()
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

    // Tests methods in player/human. Also tests computer because they only
    // differ in how they make the moves (for computers, it's random)
    // Friended by Human so can directly access members.
    static void humanTest() {

        Human * test = new Human("test");

        // Getter Functions
        assert(test->getName() == "test");
        assert(test->hand == test->getHand());
        assert(test->discardPiles == test->getDiscardPiles());
        assert(test->stockPile == test->getStockPile());

	/* // Set Turn function
        assert(!test->isTurn);
        assert(test->setTurn());
        assert(test->isTurn);
	*/
	
        // Add card to hand
        Card c0(0);
        assert(test->addCardToHand(&c0));
        Card c1(1);
        assert(test->addCardToHand(&c1));
        Card c2(2);
        assert(test->addCardToHand(&c2));
        Card c3(3);
        assert(test->addCardToHand(&c3));
        Card c4(4);
        assert(test->addCardToHand(&c4));
        Card c5(5);
        assert(!test->addCardToHand(&c5));  // Can't add 6th card to hand

        // Remove card from hand
        assert(0 == test->removeCardFromHand(0)->getVal());
        assert(1 == test->removeCardFromHand(1)->getVal());
        assert(2 == test->removeCardFromHand(2)->getVal());
        assert(3 == test->removeCardFromHand(3)->getVal());
        assert(4 == test->removeCardFromHand(4)->getVal());

        // Add card to Stock Pile
        Card c6(6);
        assert(test->addCardToStockPile(&c6));
        Card c7(7);
        assert(test->addCardToStockPile(&c7));

        // Remove card from StockPile
        assert(7 == test->removeFromStockPile()->getVal());
        assert(6 == test->removeFromStockPile()->getVal());
    }

    // Tests addPlayer(...), which effectively tests setPlayers.
    // Tests validMove(...) and moveCard(...) which tests the entire making move process.
    // Tests dealCards(...).
    // Tests gameOver() at the end.
    static void gameTest() {
        Game test;
        Human * p1 = new Human("testp1");
        Human * p2 = new Human("testp2");

        // Testing addPlayer()
        test.addPlayer(p1);
        test.addPlayer(p2);
        assert(test.players[0]->getName() == p1->getName());
        assert(test.players[1]->getName() == p2->getName());

        // Testing dealCards()
        test.dealCards(3);
        assert(test.players[0]->getStockPile()->getSize() == 3);
        assert(test.players[1]->getStockPile()->getSize() == 3);
        assert(test.drawPile->getSize() == 146);    // 162 - (3+3) - (5+5) = 156

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

        // Game not over
        assert(!test.gameOver());

        // Doesn't switch players for our tests
        assert(test.validMove('5', '8')); // Hand to Discard Pile (turn over)
        test.moveCard('5', '8');
        assert(test.players[0]->getDiscardPiles()[2]->top()->getVal() == 0);
        assert(test.players[0]->getDiscardPiles()[2]->getSize() == 1);

        // Last StockPile card to Build Pile (game over)
        assert(test.validMove('0', 'a')); 
        test.moveCard('0', 'a');
        assert(test.buildPiles[0]->top()->getVal() == 0);
        assert(test.buildPiles[0]->getSize() == 3);

        // Tests gameOver() because game is over
        assert(test.gameOver());
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
    TestMain::humanTest();
    cout << "Human Tests passed." << endl;
    TestMain::gameTest();
    cout << "Game Tests passed." << endl;

    return 0;
}
