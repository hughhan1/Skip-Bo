

CC = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g

bin: SkipBo

test: libTest
	@./libTest

libTest: Card.cpp Pile.cpp DrawPile.cpp BuildPile.cpp DiscardPile.cpp StockPile.cpp Hand.cpp\
	 Player.cpp Human.cpp Computer.cpp Game.cpp testMain.cpp
	@$(CC) $(CXXFLAGS) Card.cpp Pile.cpp DrawPile.cpp BuildPile.cpp DiscardPile.cpp\
	 StockPile.cpp Hand.cpp Player.cpp Human.cpp Computer.cpp Game.cpp testMain.cpp -o libTest
clean:
	@rm -f *~ *.o libTest
