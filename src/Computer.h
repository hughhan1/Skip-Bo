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
	TopPile* buildChoices[4];

public:
	Computer(std::string = "no name");
	void importChoices(TopPile**);
	char moveFrom();
	char moveTo();
};

#endif
