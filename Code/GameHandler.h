#ifndef __GAME_HANDLER_H__
#define __GAME_HANDLER_H__

class GameHandler{
 private:
  Game * game;
  
 public:
  void startGame();
  void loadGame();
  void saveGame();
  void endGame();
};

#endif
