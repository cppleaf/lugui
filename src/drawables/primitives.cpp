#include "primitives.h"

void Line::addPoint(Point point) { points.push_back(point); }

void Line::draw(SDL_Renderer *renderer) {
  for (int i = 0; i < points.size() - 1; ++i) {
    Point p1 = points[i];
    Point p2 = points[i + 1];

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);
  }
}
