#ifndef _NUM_PLAYERS_EXCEPTION_H
#define _NUM_PLAYERS_EXCEPTION_H

#include <iostream>
#include <exception>

class NumPlayersException : public std::exception {
public:
  const char* what() const throw(){
		return "Skip-Bo is played with 2 to 6 players.";
	}
};

#endif
