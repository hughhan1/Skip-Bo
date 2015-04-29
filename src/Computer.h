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

class Computer : public Player {
private:
	bool hasMove;

public:
	Computer(std::string = "no name");
	int moveFrom();
	int moveTo(int);
};

#endif
