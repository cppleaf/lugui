#include "primitives.h"
#include "shapes.h"

struct Clickable : public Drawable {
  virtual bool contains(double x, double y) = 0;
  virtual void onClick() = 0;

  virtual ~Clickable() = default;
};

class Button : public Clickable {
public:
  Button(Rectangle base);
  void draw(SDL_Renderer *renderer) override;

  bool contains(double x, double y) override;
  void onClick() override;

private:
  Rectangle base;
};
