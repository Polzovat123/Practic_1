#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <stdio.h>

using namespace std;

class Matrix
{
  public:
  vector < vector<double>> base;
  double *determenant;
    int num_col, num_str;
  Matrix(int x, int y)
  {
    num_col = x;
    num_str = y;
  };

    void read_matrix_random()
    {
    double a[100][100];
    srand(time(0));
    for(int i=0; i<num_col; i++){
        vector <double> str;
        for(int j=0; j<num_str; j++){
            str.push_back(double(rand()/100)/100);
        }
        base.push_back(str);
    }
  }

    void read_matrix_console()
    {
        double var;
        for(int i=0; i<num_col; i++){
            vector <double> str;
            for(int j=0; j<num_str; j++){
                cin>>var;
                str.push_back(var);
            }
            base.push_back(str);
        }
    }

    void read_matrix_file()
    {
        ifstream in("Matrix.txt");
        double var;
        for(int i=0; i<num_col; i++){
            vector <double> str;
            for(int j=0; j<num_str; j++){
                in>>var;
                str.push_back(var);
            }
            base.push_back(str);
        }
    }

    void show_matrix()
    {
    for(int i=0; i<num_col; i++){
        for(int j=0; j<num_str; j++){
            //printf("%e  ", &base[i][j]);
            cout<<base[i][j]<<"  ";
        }
        cout<<endl;
    }
  }

  void get_determenant(){
    return;
  }

  protected:
  /*список средств, доступных при наследовании*/
};

void show(){}

int main()
{
    int n, l;
    cin>>n>>l;
    Matrix A(n, l);
    A.read_matrix_random();
    A.show_matrix();
    return 0;
}
