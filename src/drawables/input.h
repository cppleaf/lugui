#include "primitives.h"
#include "shapes.h"
#include <functional>

struct EventListener : public Drawable {
  virtual void onEvent(SDL_Event e) = 0;

  virtual ~EventListener() = default;
};

class Button : public EventListener {
public:
  Button(Rectangle base, std::function<void()> callback);
  void draw(SDL_Renderer *renderer) override;

  void onEvent(SDL_Event e) override;

private:
  Rectangle base;

  std::function<void()> callback;
};
