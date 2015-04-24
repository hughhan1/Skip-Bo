#include <iostream>
#include "DrawPile.h"

using namespace std; // just for convenience while testing. 

int main() {
  cout<<"Testing"<<endl;
  Card * card;
  DrawPile* deck = new DrawPile();

  for(int i = 0; i < 162; i++){
    card = deck->remove();
    cout<<card->getVal()<<endl;
  }

  
  cout<<"Test End"<<endl;
  return 0;
}
