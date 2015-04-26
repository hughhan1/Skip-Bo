

CC = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g

bin: SkipBo
	@./SkipBo

test: sampTest
	@./sampTest

#libTest: Card.cpp Pile.cpp DrawPile.cpp BuildPile.cpp DiscardPile.cpp StockPile.cpp Hand.cpp\
#	 Player.cpp Human.cpp Computer.cpp Game.cpp TestMain
#	@$(CC) $(CXXFLAGS) Card.cpp Pile.cpp DrawPile.cpp BuildPile.cpp DiscardPile.cpp\
#	 StockPile.cpp Hand.cpp Player.cpp Human.cpp Computer.cpp Game.cpp TestMain.cpp -o libTest

SkipBo:	Card.cpp Pile.cpp DrawPile.cpp DiscardPile.cpp BuildPile.cpp StockPile.cpp Game.cpp GameController.cpp\
	 Player.cpp Human.cpp Computer.cpp Hand.cpp SkipBo.cpp
	@$(CC) $(CXXFLAGS) Card.cpp Pile.cpp DrawPile.cpp DiscardPile.cpp BuildPile.cpp StockPile.cpp Game.cpp GameController.cpp\
         Player.cpp Human.cpp Computer.cpp Hand.cpp SkipBo.cpp -o SkipBo

sampTest: Card.cpp Pile.cpp DrawPile.cpp DiscardPile.cpp BuildPile.cpp StockPile.cpp Game.cpp Player.cpp Human.cpp Computer.cpp\
	 Hand.cpp TestMain.cpp 
	@$(CC) $(CXXFLAGS) Card.cpp Pile.cpp DrawPile.cpp DiscardPile.cpp BuildPile.cpp StockPile.cpp Game.cpp\
	 Player.cpp Human.cpp Computer.cpp Hand.cpp TestMain.cpp -o sampTest













Card.o: Card.cpp Card.h
	@$(CC) $(CXXFLAGS) -c -o Card.cpp

DrawPile.o: DrawPile.cpp Card.h Pile.h DrawPile.h 
	@$(CC) $(CXXFLAGS) -c -o DrawPile.cpp

Pile.o: Pile.cpp Card.h Pile.h
	@$(CC) $(CXXFLAGS) -c Pile.cpp

BuildPile.o: BuildPile.cpp Card.h Pile.h BuildPile.h
	@$(CC) $(CXXFLAGS) -c BuildPile.cpp

TestMain.o: TestMain.cpp Card.h Pile.h DrawPile.h BuildPile.h
	@$(CC) $(CXXFLAGS) -c TestMain.cpp


clean:
	@rm -rf *~ *.o libTest sampTest skipBo *.dSYM
