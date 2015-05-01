#ifndef __EMPTY_PILE_EXCEPTION_H__
#define __EMPTY_PILE_EXCEPTION_H__

#include <iostream>
#include <exception>

class EmptyPileException : public std::exception {
public:
	void showErrorMessage() {
    	std::cout << "Pile Empty Error" <<std::endl;
   	};
};

#endif
