#include "Window.h"

Window::~Window() {
  if (renderer)
    SDL_DestroyRenderer(renderer);
  if (window)
    SDL_DestroyWindow(window);

  SDL_Quit();
}

bool Window::init() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    return false;
  }
  if (!SDL_CreateWindowAndRenderer("lugui", 640, 480, 0, &window, &renderer)) {
    return false;
  }
  return true;
}

void Window::add(Drawable *drawable) { drawables.push_back(drawable); }

void Window::clear() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
}

void Window::draw() {
  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        quit = true;
      }

      clear();

      for (Drawable *drawable : drawables) {
        drawable->draw(renderer);
      }

      SDL_RenderPresent(renderer);
    }
  }
}
