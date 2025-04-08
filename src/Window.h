#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "drawables/input.h"
#include "drawables/primitives.h"

class Window {
public:
  ~Window();

  bool init();

  void add(Drawable *drawable);
  void add(Clickable *clickable);

  void clear();

  void run();

private:
  SDL_Renderer *renderer;
  SDL_Window *window;

  std::vector<Drawable *> drawables;
  std::vector<Clickable *> clickables;
};
