#include "Window.h"
#include "drawables/shapes.h"
#include <iostream>

int main() {
  Window window;
  window.init();

  Rectangle rect(250, 100, 100, 300);
  Button button(rect, []() { std::cout << "Button clicked" << '\n'; });

  Rectangle rect2(50, 50, 50, 20);
  TextInput input(rect2);

  window.add(&button);
  window.add(&input);
  window.run();

  return 0;
}
