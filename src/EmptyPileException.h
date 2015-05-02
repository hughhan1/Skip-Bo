#ifndef __EMPTY_PILE_EXCEPTION_H__
#define __EMPTY_PILE_EXCEPTION_H__

#include <iostream>
#include <exception>

class EmptyPileException : public std::exception {
public:
  const char* what() const throw(){
		return "Empy Pile Exception.";
	}
};

#endif
