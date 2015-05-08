/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Computer.h
 */

#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "Player.h"
#include <cstdlib>

#define NUM_MOVE_FROM 10
#define NUM_MOVE_TO 8
#define ASCII_SHIFT 48

class Computer : public Player {
private:
	/** FOR EXTRA CREDIT. */
	TopPile* buildChoices[4];
	Card * moveCard;

public:
	/** Constructor. */
	Computer(std::string = "no name");

	/** Destructor. */
	virtual ~Computer();

	/** FOR EXTRA CREDIT. */
	void importChoices(TopPile**);

	/**
	 * Returns where the card should be moved from.
	 * @return where the card should be moved from
	 */
	char moveFrom();

	/**
	 * Returns where the card should be moved to.
	 * @return where the card should be moved to
	 */
	char moveTo();
};

#endif
