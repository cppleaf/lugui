#include "shapes.h"

Rectangle::Rectangle(double x, double y, double width, double height) {
  base.x = x;
  base.y = y;
  base.w = width;
  base.h = height;
}

void Rectangle::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderRect(renderer, &base);
}

bool Rectangle::contains(double x, double y) {
  return base.x <= x && base.x + base.w >= x && base.y <= y &&
         base.y + base.h >= y;
}
