#ifndef __INVALID_MOVE_EXCEPTION_H__
#define __INVALID_MOVE_EXCEPTION_H__

#include <iostream>
#include <exception>

class InvalidMoveException : public std::exception {
public:
	const char* what() {
		return "Invalid move.";
	}
};

#endif
