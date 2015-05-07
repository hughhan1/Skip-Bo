void Game::play() {

  int numPlayers = this->players.size();
  char input = '0';

  while (!gameOver() && input != 'q') {
    cout << this->players[this->turn % numPlayers]->getName() << "'s turn!" << endl;
    cout << "Enter any character to start your turn, or q to quit the game: ";
    cin >> input;

    if (input != 'q') {
      printView(this->turn % numPlayers);
      promptMove();
    } else {
      cout << endl << "Would you like to save the game (y/n)? ";
      cin >> input;

      if (input == 'y' || input == 'Y')
        saveGame();

      cout << endl << "Goodbye!" << endl;
      input = 'q';
    }
  }
}


void Game::addToDrawPile(int index) {
  this->buildPiles->shuffle();
  while (!this->buildPiles[index]->isEmpty()) {
    this->drawPile->add(this->buildPiles[index]->remove());
  }
}

void Game::endMove() {
  for (int i = 0; i < 4; i++) {
    if (this->buildPiles[i]->size() == 12) {
      addToDrawPile(i);
    }
  }
}