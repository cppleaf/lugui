#include "SDL3/SDL_render.h"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <filesystem>
#include <vector>

struct Drawable {
  virtual void draw(SDL_Renderer *renderer) = 0;
  virtual ~Drawable() = default;
};

class Window {
public:
  ~Window() {
    if (renderer)
      SDL_DestroyRenderer(renderer);
    if (window)
      SDL_DestroyWindow(window);

    SDL_Quit();
  }

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

  void add(Drawable *drawable) { drawables.push_back(drawable); }

  void clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
  }

  void draw() {
    SDL_Event e;
    bool quit = false;
    while (!quit) {
      while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT) {
          quit = true;
        }

        clear();

        for (Drawable *drawable : drawables) {
          drawable->draw(renderer);
        }

        SDL_RenderPresent(renderer);
      }
    }
  }

private:
  SDL_Renderer *renderer;
  SDL_Window *window;

  std::vector<Drawable *> drawables;
};

struct Point {
  double x, y;
};

class Line : public Drawable {
public:
  void addPoint(double x, double y) { points.push_back({x, y}); }
  void addPoint(Point point) { points.push_back(point); }

  void draw(SDL_Renderer *renderer) {
    for (int i = 0; i < points.size() - 1; ++i) {
      Point p1 = points[i];
      Point p2 = points[i + 1];

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);
    }
  }

private:
  std::vector<Point> points;
};

class Rectangle : public Line {
public:
  Rectangle(double x, double y, double width, double height) {
    addPoint(x, y);
    addPoint(x + width, y);
    addPoint(x + width, y + height);
    addPoint(x, y + height);
    addPoint(x, y);
  }
};

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
