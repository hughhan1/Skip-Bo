
void Game::endTurn() {
	
}

void Game::fillHand(int i) {
	Hand * hand = this->players[i]->getHand();
	while (!hand->isFull()) {
		hand->add(this->drawPile->remove());
	}
}