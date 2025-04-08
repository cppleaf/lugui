#include "input.h"
#include <iostream>

Button::Button(Rectangle base) : base(base) {}

void Button::draw(SDL_Renderer *renderer) { base.draw(renderer); }

bool Button::contains(double x, double y) { return base.contains(x, y); }
void Button::onClick() { std::cout << "Button clicked" << '\n'; }
