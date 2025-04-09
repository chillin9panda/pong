#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

class Window {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  const char *title;
  int width;
  int height;

public:
  Window(const char *title, int width, int height);
  ~Window();

  void createWindow();
  void destroyWindow();

  SDL_Window *getWindow() const { return window; }

  SDL_Renderer *getRenderer() const { return renderer; }
};

#endif
