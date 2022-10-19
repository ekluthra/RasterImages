#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  for (int i = 0; i < height; i++){
    for (int j = 0; j <= width/2; j++){
      for (int subpixel = 0; subpixel < num_channels; subpixel++) {
        reflected[(width * i + j) * num_channels + subpixel] = input[(width * i + (width - 1 - j)) * num_channels + subpixel];
        reflected[(width * i + (width - 1 - j)) * num_channels + subpixel] = input[(width * i + j) * num_channels + subpixel];
      }
    }
  }
}
