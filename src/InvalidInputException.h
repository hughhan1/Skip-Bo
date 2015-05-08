#ifndef _INVALID_INPUT_EXCEPTION_H
#define _INVALID_INPUT_EXCEPTION_H

#include <iostream>
#include <exception>

class InvalidInputException : public std::exception {
public:
  const char* what() const throw(){
		return "Please enter either 0 or 1.";
	}
};

#endif
