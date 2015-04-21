#ifndef _PILE_H
#define _PILE_H

#include "Card.h"
#include <deque>

class Pile {
private:
	std::deque<Card> pile;
	int size;

public:
	bool isEmpty();
	int getSize();
	virtual bool addCard() = 0;
	virtual Card removeCard() = 0;
};

#endif