#pragma once

#include "primitives.h"
#include <SDL3/SDL_rect.h>

class Rectangle : public Drawable {
public:
  Rectangle(double x, double y, double width, double height);

  void draw(SDL_Renderer *renderer) override;
  bool contains(double x, double y);

private:
  SDL_FRect base;
};
