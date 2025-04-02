#include "SDL3/SDL_render.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <vector>

struct Window {
  SDL_Renderer *renderer;
  SDL_Window *window;

  bool init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
      return false;
    }
    if (!SDL_CreateWindowAndRenderer("lugui", 640, 480, 0, &window,
                                     &renderer)) {
      return false;
    }
    return true;
  }

  void clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
  }

  void draw() { SDL_RenderPresent(renderer); }

  ~Window() {
    if (renderer)
      SDL_DestroyRenderer(renderer);
    if (window)
      SDL_DestroyWindow(window);
    SDL_Quit();
  }
};

struct Point {
  double x, y;
};

class Line {
public:
  void addPoint(Point *point) { points.push_back(point); }

  void draw(Window *window) {
    for (int i = 0; i < points.size() - 1; ++i) {
      Point *p1 = points[i];
      Point *p2 = points[i + 1];

      SDL_RenderLine(window->renderer, p1->x, p1->y, p2->x, p2->y);
    }
  }

private:
  std::vector<Point *> points;
};

int main() {
  Window window;
  if (!window.init()) {
    return 1;
  }

  Point p1{50, 100};
  Point p2{100, 100};
  Point p3{0, 0};

  Line line;
  line.addPoint(&p1);
  line.addPoint(&p2);
  line.addPoint(&p3);

  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT)
        quit = true;

      window.clear();
      SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
      line.draw(&window);
      window.draw();
    }
  }

  return 0;
}
