#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "drawables/primitives.h"

class Window {
public:
  ~Window();

  bool init();

  void add(Drawable *drawable);

  void clear();

  void draw();

private:
  SDL_Renderer *renderer;
  SDL_Window *window;

  std::vector<Drawable *> drawables;
};
