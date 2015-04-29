/**
 * Marc Feldman
 * Hugh Han
 * SeungHwan Lee
 * Matthew Cowen-Green
 *
 * EN.600.120 Intermediate Programming, Spring 2015
 * SkipBo: GameController.cpp
 */

#include "GameController.h"

void GameController::runGame() {
	srand(time(NULL));
	welcome();
	skipBo = new Game();
	skipBo->setPlayers();
	skipBo->dealCards();
	skipBo->printView(0);
}

void GameController::loadGame() {
    // TO DO
}

void GameController::saveGame() {
    // TO DO
}

void GameController::endGame() {
    // TO DO
}

void GameController::welcome() {
	std::cout << "  ___________   .__                __________        " 		<< std::endl;
	std::cout << " /   _____/  | _|__|_____          \\______   \\ ____  " 		<< std::endl;  
	std::cout << " \\_____  \\|  |/ /  \\____ \\   ______ |    |  _//  _ \\ " 	<< std::endl;
	std::cout << " /        \\    <|  |  |_> > /_____/ |    |   (  <_> )" 		<< std::endl;
	std::cout << "/_______  /__|_ \\__|   __/          |______  /\\____/ " 		<< std::endl;
	std::cout << "        \\/     \\/  |__|                    \\/        " 	<< std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "Enter q at any time to quit the game." << std::endl;
}
