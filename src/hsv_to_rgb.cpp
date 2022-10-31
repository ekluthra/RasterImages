#include "hsv_to_rgb.h"
#include <cmath>
void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  // algorithm was retrieved from the wiki page linked in the assignment handout
  // https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
  double c = s * v;
  double h2 = h / 60;
  double x = c * (1 - fabs(fmod(h2, 2) - 1));
  double m = v - c;
  if (h2 == 0){
    r = 0;
    g = 0;
    b = 0;
  } else if (0 < h2 <= 1){
    r = c;
    g = x;
    b = 0;
  } else if (1 < h2 <= 2) {
    r = x;
    g = c;
    b = 0;
  } else if (1 < h2 <= 2){
    r = x;
    g = c;
    b = 0;
  } else if (2 < h2 <= 3){
    r = 0;
    g = c;
    b = x;
  } else if (3 < h2 <= 4){
    r = 0;
    g = x;
    b = c;
  } else if (4 < h2 <= 5){
    r = x;
    g = 0;
    b = c;
  }
  r += m;
  g += m;
  b += m;
}
