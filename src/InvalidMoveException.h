#ifndef _INVALID_MOVE_EXCEPTION_H
#define _INVALID_MOVE_EXCEPTION_H

#include <iostream>
#include <exception>

class InvalidMoveException : public std::exception {
public:
  const char* what() const throw(){
		return "Invalid move.";
	}
};

#endif
