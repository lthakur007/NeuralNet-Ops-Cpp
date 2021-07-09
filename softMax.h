#include <math.h>
#include <iomanip>
#include <ios>

class SoftMax {
  public:
    int MatDim;
    double **SoftMxMat;
    int **InputMat;
    SoftMax(int **input, int dim){
      InputMat = input;
      MatDim = dim;
      SoftMxMat = new double*[MatDim];
      for (int i = 0; i < MatDim; ++i) {
        SoftMxMat[i] = new double[MatDim];
      }
    }
    void SoftMaxOp();
    void PrintSoftMxMat();
    ~SoftMax() {
      for (int i = 0; i < MatDim; ++i) {
        delete[] SoftMxMat[i];
      }
      delete[] SoftMxMat;
    }
};


void SoftMax::SoftMaxOp() {
  double m = -1, sum = 0.0, constant;
  for (int i = 0; i < MatDim; ++i) {
    for (int j = 0; j < MatDim; ++j) {
      if (m < InputMat[i][j]) {
        m = InputMat[i][j];
      }
    }
  }

  for (int i = 0; i < MatDim; ++i) {
    for (int j = 0; j < MatDim; ++j) {
    sum += exp(InputMat[i][j] - m);
    }
  }
  constant = m + log(sum);
  
  for (int i = 0; i < MatDim; ++i) {
    for (int j = 0; j < MatDim; ++j) {
    SoftMxMat[i][j] = exp(InputMat[i][j] - constant);
    }
  }
}

void SoftMax::PrintSoftMxMat() {
  //std::cout<<std::fixed;
  std::cout<<"Printing Output of SoftMax Operation..."<<std::endl;
  for (int i = 0; i < MatDim; ++i) {
    for (int j = 0; j < MatDim; ++j) {
      std::cout<<std::setw(10);
      std::cout<<SoftMxMat[i][j]<<", ";
    }
    std::cout<<std::endl;
  }
}
