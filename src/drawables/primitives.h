#pragma once

#include "SDL3/SDL_render.h"
#include <vector>

struct Drawable {
  virtual void draw(SDL_Renderer *renderer) = 0;
  virtual ~Drawable() = default;
};

struct Point {
  double x, y;
};

class Line : public Drawable {
public:
  void addPoint(Point point);
  void draw(SDL_Renderer *renderer);

private:
  std::vector<Point> points;
};
