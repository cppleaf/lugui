#include "Window.h"
#include "drawables/shapes.h"

int main() {
  Window window;
  window.init();

  Point p1{50, 100};
  Point p2{100, 100};
  Point p3{0, 0};

  Line line;
  line.addPoint(p1);
  line.addPoint(p2);
  line.addPoint(p3);

  Rectangle rect(250, 100, 100, 300);

  window.add(&line);
  window.add(&rect);
  window.draw();

  return 0;
}
