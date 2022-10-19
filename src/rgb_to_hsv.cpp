#include "rgb_to_hsv.h"
#include <cmath>
#include <algorithm>
void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  double min = std::min({r, g, b});
  double max = std::max({r, g, b});
  double c = max - min;
  // utilized an algorithm explained on this wikipedia page, also linked in the assignment description
  // https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
  if (c != 0) {
    if (max == r){
      h = 60 * fmod(((g-b)/c), 6);
    } else if (max == g){
      h = 60 * ((b-r)/c + 2);
    } else if (max == b){
      h = 60 * ((r-g)/c + 4);
    }
  } else {
    h = 0;
  }
  if (max != 0){
    s = c/max;
  } else {
    s = 0;
  }
  v = max;
}
