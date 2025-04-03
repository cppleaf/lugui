#include "primitives.h"

class Rectangle : public Drawable {
public:
  Rectangle(double x, double y, double width, double height);

  void draw(SDL_Renderer *renderer) override;

private:
  std::vector<Point> points;
};
