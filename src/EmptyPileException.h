#ifndef __EMPTY_PILE_EXCEPTION_H__
#define __EMPTY_PILE_EXCEPTION_H__

#include <iostream>

// changed our exception class just to make things simpler
class EmptyPileException {
 public:
  void showErrorMessage() {
    std::cout<< "Pile Empty Error"<<std::endl;
   };
};

#endif
