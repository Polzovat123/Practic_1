#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

class Matrix{
private:
    long long str, stl;
    long double det;
    bool calculus = false;
    vector <vector <long double>> table;
    vector <long double> srt;

    void bad_matrix(){
        cout<<"You Matrix not squire and determinant not"<<endl;
    }

    void change_line_matrix(int i_f, int i_n, int k){
        for(int i=0; i<stl; i++){
            table[i_n][i]-=k*table[i_f][i];
        }
    }

    int get_last_no_zero(int now){
        for(int i=0; i<stl; i++){
            if(table[now][i]!=0){
                return i;
            }
        }
        det = 0;
        return -101;
    }

    void change_last_matrix(int i){
        for(int j=i+1;j<stl;j++){
            int n = get_last_no_zero(j);
            if(n==-101)return;
            change_line_matrix(i, j, table[j][n]/table[i][n]);
        }
    }

    void calculus_det(){
        if(str!=stl){
            bad_matrix();
            return;
        }
        for(int i=0; i<stl; i++){
            change_last_matrix(i);
        }
        det = 1;
        for(int i=0; i<stl;i++){
            det *= table[i][i];
        }
    }

public:
    Matrix(long long n, long long m, vector<vector<long double>>&lin){
        str = n;
        stl = m;
        for(int i=0; i<n; i++){
            srt.clear();
            for(int j=0; j<m; j++){
                srt.push_back(lin[i][j]);
            }
            table.push_back(srt);
        }

    }

    long double get_determnant(){
        if(calculus){
                return det;
        }
        calculus=true;
        calculus_det();
        return det;
    }

    vector<vector<long double>>&A(){}

    void show(){
        for(int i=0; i<str; i++){
            for(int j=0; j<stl; j++){
                printf("%.2Lf ", &table[i][j]);
            }
            printf("\n");
        }
    }

};

vector <vector <long double>> input_table;
vector <long double> str;
long long n,m,a;
long double f;
long long const len_random = 3;
long long const d_maks = 900;
long long const d_mini = -500;

void rand_read(){
    srand(time(NULL));
    n = m = rand()%(len_random-1)+2;

    for(int i=0;i<n;i++){

        str.clear();
        for(int j=0;j<m;j++){
            f = (rand()%d_maks + d_mini)/100.0;
            str.push_back(f);
        }
        input_table.push_back(str);
    }
}

void file_read(string path){
    ifstream in(path);
    in>>n;
    in>>m;

    for(int i=0;i<n;i++){
        str.clear();
        for(int j=0;j<m;j++){
            in>>f;
            str.push_back(f);
        }
        input_table.push_back(str);
    }
}

void cons_read(){
    printf("Write n: ");scanf("%d", &n);
    printf("Write m: ");scanf("%d", &m);

    for(int i=0;i<n;i++){
        str.clear();
        for(int j=0;j<m;j++){
            scanf("%Lf", &f);
            str.push_back(f);
        }
        input_table.push_back(str);
    }
}

void read_data(){
    input_table.clear();
    long long ans=0;
    printf("Write methods write what you prefer(1 - random input, 2 - file input, 3 - console input):\n");
    scanf("%d", &ans);
    switch(ans){
    case 1:
        rand_read();
        break;
    case 2:
        file_read("input.txt");
        break;
    case 3:
        cons_read();
        break;
    default:
        printf("You write not correct, we read standart input\n");
        file_read("standart.txt");
    }
    return;
}

void write_determenant(long double det, string name){
    printf("det(%s)= %d", &name, &det);
}

void main_task(){
    //first
    read_data();
    Matrix a(n, m, input_table);
    a.show();
    cout<<"det(A) = "<<a.get_determnant()<<endl;

    read_data();
    Matrix b(n, m, input_table);
    b.show();
}

int main()
{
    main_task();
    return 0;
}
