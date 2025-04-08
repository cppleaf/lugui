#include "Window.h"
#include "drawables/shapes.h"

int main() {
  Window window;
  window.init();

  Rectangle rect(250, 100, 100, 300);
  Button button(rect);

  window.add(&button);
  window.run();

  return 0;
}
