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
	int stockSize = skipBo->setPlayers();
	skipBo->dealCards(stockSize);
	skipBo->play();
}

void GameController::loadGame() {
    // TO DO
}

void GameController::endGame() {
    // TO DO
}

void GameController::welcome() {

	std::cout << std::endl << std::endl;
	std::cout << "_____________________________________________________"		<< std::endl;
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl 	<< std::endl;

	std::cout << "  ___________   .__                __________        " 		<< std::endl;
	std::cout << " /   _____/  | _|__|_____          \\______   \\ ____  " 		<< std::endl;  
	std::cout << " \\_____  \\|  |/ /  \\____ \\   ______ |    |  _//  _ \\ " 	<< std::endl;
	std::cout << " /        \\    <|  |  |_> > /_____/ |    |   (  <_> )" 		<< std::endl;
	std::cout << "/_______  /__|_ \\__|   __/          |______  /\\____/ " 		<< std::endl;
	std::cout << "        \\/     \\/  |__|                    \\/        " 	<< std::endl;

	std::cout << std::endl << std::endl;

}
