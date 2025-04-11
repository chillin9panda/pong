#include "game.h"
#include "window.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>

Game::Game() : window(nullptr), isRunning(true), previousFrameTime(0) {
  window = new Window("Pong", 800, 600);
  window->createWindow();
}

Game::~Game() { delete window; }

void Game::run() {
  while (isRunning) {
    Uint64 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - previousFrameTime) / 1000.0f;
    previousFrameTime = currentTime;

    handleEvents();
    update(deltaTime);
    render();
  }
}

void Game::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      isRunning = false;
      break;

    case SDL_EVENT_KEY_DOWN: {
      if (event.key.key == SDLK_ESCAPE) {
        isRunning = false;
      }
      break;
    }
    }
  }
}

void Game::update(float deltaTime) {}

void Game::render() {
  SDL_Renderer *renderer = window->getRenderer();

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}
