#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  double r = 0.0, g = 0.0, b = 0.0, h = 0.0, s = 0.0, v = 0.0;
  for(int i = 0; i < width * height; i++){
    rgb_to_hsv((double) (rgb[3*i] / 255.0), (double) (rgb[3*i + 1] / 255.0), (double) (rgb[3*i + 2] / 255.0),h,s,v);
    h += shift;
    hsv_to_rgb(h,s,v,r,g,b);
    shifted[3 * i] = (unsigned char) (r * 255);
    shifted[(3 * i) + 1] = (unsigned char) (g * 255);
    shifted[(3 * i) + 2] = (unsigned char) (b * 255);
  }
}
