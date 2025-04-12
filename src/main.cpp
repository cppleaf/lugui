#include "Window.h"
#include "drawables/shapes.h"
#include <iostream>

int main() {
  Window window;
  window.init();

  Rectangle rect(250, 100, 100, 300);
  Button button(rect, []() { std::cout << "Button clicked" << '\n'; });

  window.add(&button);
  window.run();

  return 0;
}
