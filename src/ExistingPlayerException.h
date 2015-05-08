#ifndef _EXISTING_PLAYER_EXCEPTION_H
#define _EXISTING_PLAYER_EXCEPTION_H

#include <iostream>
#include <exception>

class ExistingPlayerException : public std::exception {
public:
  const char* what() const throw(){
		return "That player already exists.";
	}
};

#endif
