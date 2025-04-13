#include "primitives.h"
#include <string>

class Text : public Drawable {
public:
  Text(double x, double y, double scale = 1);

  void draw(SDL_Renderer *renderer) override;

  Text &operator+=(std::string str);

  std::string getText();
  void setText(std::string str);
  void pop();

private:
  std::string text;

  double x, y;
  double scale;
};
