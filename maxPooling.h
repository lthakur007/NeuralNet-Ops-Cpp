

class MaxPool {
public:
  int MatDim; // width of Square matrix(w)
  int F = 2; // Size of filter
  //int P; // Padding not implemented
  int S = 1; // Stride value
  int **Matrx;
  int MpDim; // width of output matrix of Max Pool operation
  int **MxPmat;
  MaxPool(int** Mat, int Mdim): MatDim(Mdim) {
    Matrx = Mat;
    MatDim = Mdim;
    MpDim = (Mdim - F)/S + 1;
    MxPmat = new int*[MpDim];
    for (int i = 0; i < MpDim; ++i) {
      MxPmat[i] = new int[MpDim];
    }
    std::cout<<"Filter Size used for Max Pooling: "<<F<<std::endl;
    std::cout<<"Stride: "<<S<<std::endl;
    std::cout<<"Dimension of MaxPooled Matrix: "<<MpDim<<" x "<<MpDim<<std::endl;
  }
  int** PoolOp();
  void PrintMxPmat();

};

int** MaxPool::PoolOp() {
  int a, b, c, d;
  for (int i = 0; i < MatDim; ++i) {
    for (int j = 0; j < MatDim; ++j) {
      a = Matrx[i][j];
      if ((j + 1) < MatDim) {
        b = Matrx[i][j+1];
      } else {
        continue;
      }
      if ((i + 1) < MatDim) {
        c = Matrx[i+1][j];
      } else {
        continue;
      }
      d = Matrx[i+1][j+1];
      a = (a > b) ? a : b;
      b = (c > d) ? c : d;
      a = (a > b) ? a : b;
      MxPmat[i][j] = a;
    }
  }
  return MxPmat;
}

void MaxPool::PrintMxPmat() {
  std::cout<<"Printing MaxPooled matrix..."<<std::endl;

  for (int i = 0; i < MpDim; ++i) {
    for (int j = 0; j < MpDim; ++j) {
      std::cout<<MxPmat[i][j]<<" ";  
    }
    std::cout<<std::endl;
  }
}
