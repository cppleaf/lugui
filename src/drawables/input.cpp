#include "input.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <iostream>

Button::Button(Rectangle base, std::function<void()> callback)
    : base(base), callback(callback) {}

void Button::draw(SDL_Renderer *renderer) { base.draw(renderer); }

bool Button::onEvent(SDL_Event e, SDL_Window *window) {
  if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
    if (base.contains(e.button.x, e.button.y)) {
      callback();
      return true;
    }
  }

  return false;
}

TextInput::TextInput(Rectangle base)
    : base(base), text(base.getX(), base.getY()), focused(false) {}

void TextInput::draw(SDL_Renderer *renderer) {
  base.draw(renderer);
  text.draw(renderer);
}

bool TextInput::onEvent(SDL_Event e, SDL_Window *window) {
  switch (e.type) {
  case SDL_EVENT_MOUSE_BUTTON_DOWN: {
    if (base.contains(e.button.x, e.button.y)) {
      SDL_StartTextInput(window);
      focused = true;
      return true;
    } else {
      focused = false;
      SDL_StopTextInput(window);
    }
    break;
  }
  case SDL_EVENT_KEY_DOWN: {
    if (e.key.key == SDLK_BACKSPACE && text.getText().length() > 0 && focused) {
      text.pop();
    }
    break;
  }
  case SDL_EVENT_TEXT_INPUT: {
    text += e.text.text;
    std::cout << text.getText() << '\n';
    break;
  }
  }

  return false;
}

std::string TextInput::getText() { return text.getText(); }
