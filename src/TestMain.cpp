#include <iostream>
#include <cassert>
#include "DrawPile.h"
#include "Human.h"
#include "Computer.h"
#include "Card.h"
#include "Hand.h"

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
	humanTest();

	return 0;
}
