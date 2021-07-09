#include <iomanip>
#include <ios>

class Convolve {
  public:
    int MatDim;
    int Kdim = 3;
    int CvdMDim;
    int Kernel[3][3] = {1, 1, 1, 1, 0, 1, 1, 1, 1};
    int **Matrx;
    int **ConvolvdMat;
    Convolve(int Dim): MatDim(Dim) {
      // Dim of Convolvd mat = dim of convolution matrix - dim of convolution kernel +1
      CvdMDim = MatDim - Kdim + 1;
      Matrx = new int*[MatDim];
      for (int i = 0; i < MatDim; ++i) {
        Matrx[i] = new int[MatDim];
      }
      ConvolvdMat = new int*[CvdMDim];
      for (int i = 0; i < CvdMDim; ++i) {
        ConvolvdMat[i] = new int[CvdMDim];
      }
      for (int i = 0; i < MatDim; ++i) {
        for (int j = 0; j < MatDim; ++j) {
	  Matrx[i][j] = (std::rand() % (51));
	}
      }
    }
    int** ConvolutionOp();
    void PrintConvdMatrix();
    ~Convolve() {
      for (int i = 0; i < MatDim; ++i) {
	delete[] Matrx[i];
      }
      delete[] Matrx;
    }
};

void Convolve::PrintConvdMatrix() {
  std::cout<<"Printing Input Matrix..."<<std::endl;
  std::cout<<"Matrix Size: "<<MatDim<<" x "<<MatDim<<std::endl;
  for (int i = 0; i < MatDim; ++i) {
    for (int j = 0; j < MatDim; ++j) {
      std::cout<<std::setw(4);
      std::cout << Matrx[i][j] << " ";
    }
    std::cout<<std::endl;
  }

  std::cout<<"Printing Convolved Matrix...."<<std::endl;
  for (int i = 0; i < CvdMDim; ++i) {
    for (int j = 0; j < CvdMDim; ++j) {
      std::cout << ConvolvdMat[i][j] << " ";
    }
    std::cout<<std::endl;
  }
}

int** Convolve::ConvolutionOp() {
  int kCentrX = Kdim/2;
  int kCentrY = Kdim/2;
  int temp = 0;
  for (int i = 0; i < (MatDim - Kdim + 1); ++i) {
    for (int j = 0; j < (MatDim - Kdim + 1); ++j) {
      temp = 0;
      for (int Ii = 0; Ii < Kdim; ++Ii) {
        for (int Ij = 0; Ij < Kdim; ++Ij) {
	  temp += Matrx[i+Ii][j+Ij] * Kernel[Ii][Ij];
	}
      }
      ConvolvdMat[i][j] = temp;
    }
  
  }
  return ConvolvdMat;
}
