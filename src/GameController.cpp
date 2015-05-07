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

	std::cout << "Would you like to load a game from a file or start a new game? (0 for load, 1 for new): ";
	char input;
	std::cin >> input;

	std::cout << std::endl;

	if (input == '0')
	    loadGame();
	else {
	    skipBo = new Game();
	    int stockSize = skipBo->setPlayers();
	    skipBo->dealCards(stockSize);
	}

	skipBo->play();
}

void GameController::loadGame() {
        
        FILE * inFile;
  
	std::cout << "Enter the name of the file from which you'd like to load the game: ";
	std::string filename;
	std::cin >> filename;
	
	inFile = fopen(filename.c_str(), "r");
	
	if (!inFile) {
	     std::cerr << "Error opening file: " << filename << std::endl;
	     exit(1);
	} else
	     skipBo = new Game(inFile);
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
