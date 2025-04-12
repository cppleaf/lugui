#include "input.h"

Button::Button(Rectangle base, std::function<void()> callback)
    : base(base), callback(callback) {}

void Button::draw(SDL_Renderer *renderer) { base.draw(renderer); }

void Button::onEvent(SDL_Event e) {
  if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
    if (base.contains(e.button.x, e.button.y)) {
      callback();
    }
  }
}
