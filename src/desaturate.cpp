#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  double h = 0, s = 0, v = 0;
  for (int i = 0; i < height * width; i++){
    double r = (double) (rgb[i * 3] / 255.0);
    double g = (double) (rgb[i * 3+ 1] / 255.0);
    double b = (double) (rgb[i * 3+ 2] / 255.0);
    rgb_to_hsv(r, g, b, h, s, v);
    s *= (1.0 - factor);
    hsv_to_rgb(h, s, v, r, g, b);
    desaturated[i * 3] = (unsigned char) (r * 255.0);
    desaturated[i * 3 + 1] = (unsigned char) (g * 255.0);
    desaturated[i * 3 + 2] = (unsigned char) (b * 255.0);
  }
}
