CC = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g

SRC = \
	Card.cpp\
	Pile.cpp\
	DrawPile.cpp\
	TopPile.cpp\
	Game.cpp\
	GameController.cpp\
	Player.cpp\
	Human.cpp\
	Computer.cpp\
	Hand.cpp

bin: SkipBo
	@./SkipBo

test: sampTest
	@./sampTest

SkipBo:	$(SRC) SkipBo.cpp
	@$(CC) $(CXXFLAGS) $(SRC) SkipBo.cpp -o SkipBo

sampTest: $(SRC) TestMain.cpp 
	@$(CC) $(CXXFLAGS) $(SRC) TestMain.cpp -o sampTest

Card.o: Card.cpp Card.h
	@$(CC) $(CXXFLAGS) -c -o Card.cpp

Pile.o: Pile.cpp Card.h Pile.h
	@$(CC) $(CXXFLAGS) -c Pile.cpp

DrawPile.o: DrawPile.cpp Card.h Pile.h DrawPile.h 
	@$(CC) $(CXXFLAGS) -c -o DrawPile.cpp

TopPile.o: TopPile.cpp Card.h Pile.h TopPile.h 
	@$(CC) $(CXXFLAGS) -c -o TopPile.cpp

TestMain.o: TestMain.cpp Card.h Pile.h DrawPile.h TopPile.h
	@$(CC) $(CXXFLAGS) -c TestMain.cpp

clean:
	@rm -rf *~ *.o libTest sampTest skipBo *.dSYM
