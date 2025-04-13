#include "text.h"

Text::Text(double x, double y, double scale) : x(x), y(y), scale(scale) {};

void Text::draw(SDL_Renderer *renderer) {
  // TODO: 2D scale, proper drawing

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_SetRenderScale(renderer, scale, scale);
  SDL_RenderDebugText(renderer, x, y, text.c_str());
};

Text &Text::operator+=(std::string str) {
  text += str;
  return *this;
};

std::string Text::getText() { return text; };
void Text::setText(std::string str) { text = str; };
void Text::pop() { text.pop_back(); }
