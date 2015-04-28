/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Pile.cpp
 */

#include "EmptyPileException.h"
#include "Pile.h"

bool Pile::isEmpty() const {
  return pile.size() == 0;
}

int Pile::getSize() const {
  return pile.size();
}

/* Pure Virtual
bool Pile::add(Card* c) {
    this->pile.push_back(c);
    return true;
}
*/

Card * Pile::remove() {
  // Adding try catch here temporarily.
  try{
    if (isEmpty()) {
      //throw EmptyPileException();
      throw -1;
    } else {
        Card * c = pile.back();
        pile.pop_back();
        return c;
    }
  }
  /*catch(EmptyPileException &excpt){
    excpt.showErrorMessage();
  }
  */
  catch(int excpt){
    std::cout<<"Pile Empty Error"<<std::endl;
  }

}

void Pile::shuffle() {
  std::random_shuffle(this->pile.begin(), this->pile.end());
}
