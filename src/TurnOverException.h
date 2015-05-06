#ifndef __TURN_OVER_EXCEPTION_H__
#define __TURN_OVER_EXCEPTION_H__

#include <iostream>
#include <exception>

class TurnOverException : public std::exception {
public:
	const char* what() const throw() {
		return "Your turn is over.";
	}
};

#endif
