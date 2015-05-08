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

	bool check = false;

	if (input == '1')
	    check = loadGame();
	
	if (!check) {
	    skipBo = new Game();
	    int stockSize = skipBo->setPlayers();
	    skipBo->dealCards(stockSize);
	}

	skipBo->play();
}

bool GameController::loadGame() {

        char in = '0';
        char load = '0';
	
	while (in == '0' && (load != 'y' && load != 'Y')) {
	  std::cout << "Enter the name of the file from which you'd like to load the game: ";
	  std::string filename;
	  std::cin >> filename;

	  std::ifstream inFile(filename, std::ios::in);

	  if (!inFile) {  
	    std::cerr << "Error opening file: " << filename << std::endl << std::endl;
	    std::cout << "Would you like to start a new game? (y/n): ";
	    std::cin >> load;
	    std::cout << std::endl;
	    
	    if (load == 'y' || load == 'Y')
	      return false;

	  } else {
	    skipBo = new Game(inFile);
	    return true;
	  }
	}
	return false; 
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
