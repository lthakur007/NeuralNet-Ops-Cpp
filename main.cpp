
#include <iostream>
#include "convolution.h"
#include "maxPooling.h"
#include "softMax.h"
using namespace std;

int main() {

  int MatDim;
  do {
    std::cout<<"Please provide the width of a Square Matrix atleast > 3:"<<std::endl;
    std::cin>>MatDim;
  }while(MatDim <= 3);
  // convolvd matrix will be of size = MatDim - Kdim(3) + 1
  int CMat = MatDim - 2;
  int **ConvldMat = new int*[CMat];

  Convolve obj(MatDim);
  ConvldMat = obj.ConvolutionOp();
  obj.PrintConvdMatrix();
  std::cout<<std::endl<<std::endl;;

  // Max Pooled Matrix size will be = (CMat - FilterSz(2))/Stride(1) + 1
  int MxPldMatDim = (CMat - 2)/1 + 1;
  int **MxPldMat = new int*[MxPldMatDim];

  
  // Creating object for MaxPool operation
  MaxPool mp(ConvldMat, CMat);
  MxPldMat = mp.PoolOp();
  mp.PrintMxPmat();

  std::cout<<std::endl<<std::endl;;
  
  SoftMax SMx(MxPldMat, MxPldMatDim);
  SMx.SoftMaxOp();
  SMx.PrintSoftMxMat();

  std::cout<<std::endl<<std::endl;;

  for (int i = 0; i < CMat; ++i) {
    delete[] ConvldMat[i];
  }
  delete[] ConvldMat;

  for (int i = 0; i < MxPldMatDim; ++i) {
    delete[] MxPldMat[i];
  }
  delete[] MxPldMat;
}
