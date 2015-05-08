/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Human.h
 */

#ifndef _HUMAN_H
#define _HUMAN_H

#include "Player.h"
#include <iostream>

class Human : public Player {

	/** For testing purposes. */
 	friend class TestMain;

public:
	/** Constructor. */
	Human(std::string name = "no name");

	/** Destructor. */
	virtual ~Human();

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
