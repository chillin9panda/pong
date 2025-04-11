#ifndef GAME_H
#define GAME_H

#include "window.h"
#include <SDL3/SDL_stdinc.h>

class Game {
private:
  void handleEvents();
  void update(float deltaTime);
  void render();

  Window *window;
  bool isRunning;
  Uint64 previousFrameTime;

public:
  Game();
  ~Game();

  void run();
};

#endif
