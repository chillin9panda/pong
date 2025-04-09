#include "window.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>

int main() {
  Window window("Pong", 800, 600);
  window.createWindow();

  bool running = true;
  SDL_Event e;

  while (running) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_EVENT_QUIT:
        running = false;
        break;

      case SDL_EVENT_KEY_DOWN: {
        if (e.key.key == SDLK_ESCAPE) {
          running = false;
        }
        break;
      }
      }
    }

    // Clear Screen
    SDL_SetRenderDrawColor(window.getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(window.getRenderer());

    // Draw Game

    // Display
    SDL_RenderPresent(window.getRenderer());
  }

  return 0;
}
