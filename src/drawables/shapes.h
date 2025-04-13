#pragma once

#include "primitives.h"
#include <SDL3/SDL_rect.h>

class Rectangle : public Drawable {
public:
  Rectangle(double x, double y, double width, double height);

  void draw(SDL_Renderer *renderer) override;
  bool contains(double x, double y);

  double getX() { return base.x; }
  double getY() { return base.y; }
  double getWidth() { return base.w; }
  double getHeight() { return base.h; }

private:
  SDL_FRect base;
};
