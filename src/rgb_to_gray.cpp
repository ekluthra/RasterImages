#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  // the wikipedia page linked on the assignment handout used these values
  // https://en.wikipedia.org/wiki/Grayscale#Converting_color_to_grayscale
  for (int i = 0; i < width * height; i++){
    double pixel = (double) (0.2126 * (rgb[3*i]) + 0.7152 * (rgb[i*3+1]) + 0.0722 * (rgb[i*3+2]));
    gray[i] = (unsigned char) (pixel);
  }
}


