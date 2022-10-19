#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  // for(int i = 0; i < height; i++){
  //   for(int j = 0; j < width; j++){

  //   }
  // }
}
