#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);

  int i = 0;
  int j = 0;
  while (i < rgba.size()){
    if ((i+1) % 4 != 0){
      rgb[j] = rgba[i];
      j++;
    }
    i++;
  }
}
