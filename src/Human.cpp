/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: Human.cpp
 */

#include "Human.h"
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

Human::Human(std::string name) : Player(name) { }

char Human::moveFrom() {
    char ch;
    cout << "Enter a number representing a card you would like to move: "; 
    cin >> ch;
    cout << endl;
    return ch;
}

char Human::moveTo() {
    char ch;
    cout << "Enter a number representing a pile to which you would like to move that card: ";
    cin >> ch;
    cout << endl;
    return ch;
}
