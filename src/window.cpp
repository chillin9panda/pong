#include "window.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cstdlib>
#include <iostream>

Window::Window(const char *title, int width, int height)
    : title(title), width(width), height(height), window(nullptr),
      renderer(nullptr) {}

Window::~Window() { destroyWindow(); }

void Window::createWindow() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL Could not initialize! SDL_ERROR: " << SDL_GetError()
              << std::endl;
    exit(1);
  }

  window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
  if (!window) {
    std::cerr << "Window could not be created! SDL_ERROR: " << SDL_GetError()
              << std ::endl;
    exit(1);
  }

  SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    std::cerr << "Renderer could not be created! SDL_ERROR: " << SDL_GetError()
              << std::endl;
    exit(1);
  }
}

void Window::destroyWindow() {
  if (renderer) {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  if (window) {
    SDL_DestroyWindow(window);
    window = nullptr;
  }
}
