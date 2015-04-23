/**
 * SegFaults
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: CheckMoves.cpp
 */

#include "CheckMoves.h"

bool CheckMoves::canDraw(Player& player) {
	return !player.hand().isEmpty()
}

bool CheckMoves::canRemove(Pile& pile) {
	if (BuildPile b = dynamic_cast<BuildPile>(pile)
			|| DrawPile d = dynamic_cast<DrawPile>(pile)) {
		return false;
	} else {
		return true;
	}
}

bool CheckMoves::canRemove(Hand& hand) {
	return !hand.isEmpty();
}

bool CheckMoves::canBuild(Card& card, Pile& pile) {
	if (BuildPile b = dynamic_cast<BuildPile>(pile)) {
		return card.getVal() == 0
				|| card.getVal() == pile.top().getVal() + 1;
	} else {
		return false;
	}
}
