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

class Computer : public Player {
public:
	Computer(std::string = "no name");
	char moveFrom();
	char moveTo();
};

#endif
