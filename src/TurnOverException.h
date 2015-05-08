#ifndef _TURN_OVER_EXCEPTION_H
#define _TURN_OVER_EXCEPTION_H

#include <iostream>
#include <exception>

class TurnOverException : public std::exception {
public:
	const char* what() const throw() {
		return "Your turn is over.";
	}
};

#endif
