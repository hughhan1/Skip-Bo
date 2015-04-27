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

class Human : public Player {
public:
	Human(std::string name = "no name");
	void move();
};



//TEST FUNCTIONS

void humanTest();

#endif
