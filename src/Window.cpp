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
void Window::add(Clickable *clickable) {
  drawables.push_back(clickable);
  clickables.push_back(clickable);
}

void Window::clear() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
}

void Window::run() {
  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_EVENT_QUIT: {
        quit = true;
        break;
      }
      case SDL_EVENT_MOUSE_BUTTON_DOWN: {
        for (Clickable *clickable : clickables) {
          if (clickable->contains(e.button.x, e.button.y)) {
            clickable->onClick();
          }
          break;
        }
        break;
      }
      }

      clear();

      for (Drawable *drawable : drawables) {
        drawable->draw(renderer);
      }

      SDL_RenderPresent(renderer);
    }
  }
}
