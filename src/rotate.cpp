#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      rotated[3 * ((width - 1 - j) * height + i)] = input[3 * (i * width + j)];
      if (num_channels == 3){
        rotated[3 * ((width - 1 - j) * height + i) + 1] = input[3 * (i * width + j) + 1];
        rotated[3 * ((width - 1 - j) * height + i) + 2] = input[3 * (i * width + j) + 2];
      }
    }
  }
}
