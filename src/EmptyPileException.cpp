#include <iostream>
#include <exception>

class EmptyPileException : public std::exception {
	virtual const char* what() const throw() {
		return "Empty Pile Exception.";
	}
};