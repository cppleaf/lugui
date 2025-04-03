#include "shapes.h"

Rectangle::Rectangle(double x, double y, double width, double height) {
  points = {
      {x, y}, {x + width, y}, {x + width, y + height}, {x, y + height}, {x, y}};
}

void Rectangle::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  for (int i = 0; i < points.size() - 1; ++i) {
    SDL_RenderLine(renderer, points[i].x, points[i].y, points[i + 1].x,
                   points[i + 1].y);
  }
}
