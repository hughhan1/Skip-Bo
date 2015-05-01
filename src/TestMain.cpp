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

using std::cout; 
using std::endl; 

int main() {
  
  cout << "Testing." << endl;
  CardTest();
  cout << "Card Tests passed." << endl;
  HandTest();
  cout << "Hand Tests passed." << endl;
  DrawPileTest();
  cout << "Draw Pile Tests passed." << endl;
  StockPileTest();
  cout << "Stock Pile Tests passed." << endl;
  BuildPileTest();
  cout << "Build Pile Tests passed." << endl;
  humanTest();
  
  return 0;
}
