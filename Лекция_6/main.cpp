#include <iostream>

using namespaxe std;

class Matrix
{
  public:
  double *base;
  double determenant;
  
  Matrix(double *arr, int x, int y){
    base =  new long double[100][100];
    for(int i=0; i<x; i++){
      for(int j=0; j<y; j++){
	base[i][j] = arr[i][j];
      }
    }
  };

  void get_determenant(){
    
    return;
  }
  
  protected:
  /*список средств, доступных при наследовании*/
};

void 


int main()
{
  
  return 0;
}
