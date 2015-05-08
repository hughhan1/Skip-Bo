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

	std::cout << "Would you like to load a game from a file or start a new game? (0 for new, 1 for load): ";
	char input;
	std::cin >> input;

	std::cout << std::endl;

	if (input == '1')
	    loadGame();
	else {
	    skipBo = new Game();
	    int stockSize = skipBo->setPlayers();
	    skipBo->dealCards(stockSize);
	}

	skipBo->play();
	delete skipBo;
}

void GameController::loadGame() {

    char in = '0';
        
	while (in == '0') {
		std::cout << "Enter the name of the file from which you'd like to load the game: ";
		std::string filename;
		std::cin >> filename;

		std::ifstream inFile(filename, std::ios::in);

		if (!inFile)
			std::cerr << "Error opening file: " << filename << std::endl << std::endl;
		else {
		    in = '1';
		    skipBo = new Game(inFile);
		}
	}
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
