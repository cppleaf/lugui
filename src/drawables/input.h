#include "primitives.h"
#include "shapes.h"
#include "text.h"
#include <functional>
#include <string>

struct EventListener : public Drawable {
  virtual bool onEvent(SDL_Event e, SDL_Window *window) = 0;

  virtual ~EventListener() = default;
};

class Button : public EventListener {
public:
  Button(Rectangle base, std::function<void()> callback);

  void draw(SDL_Renderer *renderer) override;
  bool onEvent(SDL_Event e, SDL_Window *window) override;

private:
  Rectangle base;

  std::function<void()> callback;
};

class TextInput : public EventListener {
public:
  TextInput(Rectangle base);

  void draw(SDL_Renderer *renderer) override;
  bool onEvent(SDL_Event e, SDL_Window *window) override;

  std::string getText();

private:
  bool focused;
  Text text;

  Rectangle base;
};
