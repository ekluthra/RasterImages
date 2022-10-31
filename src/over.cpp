#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  for (int i = 0; i < A.size(); i += 4){
    double alphaA = A[i+3];
    double alphaB = B[i+3];
    for (int j = 0; j < 3; j++){
      C[i+j] = (unsigned char) (alphaA * (1-alphaB));
    }
    C[i] = (unsigned char) (A[i] * alphaA + B[i] * alphaB * (1-alphaA));
  }
}
