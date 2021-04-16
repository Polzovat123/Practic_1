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
    bool calc_inA = false;
    bool have_determanant = true;
    vector <vector <long double>> table;
    vector <vector <long double>> main;
    vector <vector <long double>> E;
    vector <vector <long double>> inA;
    vector <long double> B_line;
    vector <long double> B_god;
    vector <long double> srt;

    void __init__table_inverse(){
        for(int i=0; i<str; ++i){
            for(int j=0; j<stl; ++j){
                table[i][j] = inA[i][j];
            }
        }
    }

    void __init_B(){
        for(int i=0; i<B_line.size(); ++i){
            B_god.push_back(B_line[i]);
        }
    }

    bool check_and_message_zero_det(){
        if( abs(abs(det) - 0.0) < 0.0001 ){
            printf("Determenant zero => we can`t find inverse matrix");
            return true;
        }
        return false;
    }

    void init_E(){
        vector <long double> line;
        for(int i=0; i<str; i++){
            line.clear();
            for(int j=0; j<str; j++){
                if(i!=j)line.push_back(0.0);
                else line.push_back(1.0);
            }
            E.push_back(line);
        }
    }

    void init_inA(){
        vector <long double> line;
        for(int i=0; i<str; i++){
            line.clear();
            for(int j=0; j<str; j++){
                line.push_back(table[j][i]);
            }
            inA.push_back(line);
        }

    }
    ///very dangerous
    void __init__main(){
        vector <long double> line;
        for(int i=0; i<str; i++){
            line.clear();
            for(int j=0; j<str; j++){
                line.push_back(table[i][j]);
            }
            main.push_back(line);
        }
    }

    void remember_main(){
        for(int i=0; i<str; i++){
            for(int j=0; j<stl; j++){
                table[i][j] = main[i][j];
            }
        }
    }

    void cut_the_line(int now_line, long double k){
        for(int i=0; i<stl; i++){
            inA[now_line][i] /= k;
            E[now_line][i] /=k;
        }
    }

    void change_line_matrixs(int i_f, int i_n, int k){
        for(int i=0; i<stl; i++){
            inA[i_n][i]-=k*inA[i_f][i];
            E[i_n][i] -= k*E[i_f][i];
        }
    }

    void change_remainder_matrix(int now_line){
        for(int i=now_line+1; i<str; i++){
            long double k = inA[i][now_line]/inA[now_line][now_line];
            change_line_matrixs(now_line, i, k);
        }
        return;
    }

    void completion_of_the_matrix_above(int now_line){
        for(int i=now_line-1; i>-1; i--){
            change_line_matrixs(now_line, i, inA[i][now_line]);
        }
        return;
    }

    void swap_E_inA(){
        for(int i=0; i<str;i++){
            for(int j=0; j<str; j++){
                swap(E[i][j], inA[i][j]);
            }
        }
    }

    void sh(){
        for(int i=0; i<str;++i){
            for(int j=0;j<str;++j){
                cout<<inA[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void ch(){
        for(int i=0; i<str;++i){
            for(int j=0;j<str;++j){
                cout<<E[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void calculus_inA(){
        if(str!=stl){bad_matrix();return;}
        if(check_and_message_zero_det()){return;}
        init_E();
        init_inA();
        for(int i=0; i<str; i++){
            change_remainder_matrix(i);
            cut_the_line(i, inA[i][i]);
        }

        for(int i=str-1; i>0; i--){
            completion_of_the_matrix_above(i);
        }
        swap_E_inA();
    }

    ///Show

    void error_120(){
        cout<<"B have more or less length that main matrix, recomend check"<<endl;
        cout<<"ERROR-120"<<endl;
    }

    /// Check have old version
    bool check_have_inA(){
        if(!calc_inA){
            calculus_inA();
            calc_inA = true;
        }
    }

    ///Methods for determenant

    void __init__table(){
        for(int i=0; i<str; ++i){
            for(int j=0; j<stl; ++j){
                table[i][j] = main[i][j];
            }
        }
    }

    void bad_matrix(){
        cout<<"You Matrix not squire and determinant not"<<endl;
        have_determanant = false;
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
        __init__main();
    }

    Matrix(long long n, long long m, vector<vector<long double>>&lin, vector<int>line_B){
        str = n;
        stl = m;
        for(int i=0; i<n; i++){
            srt.clear();
            for(int j=0; j<m; j++){
                srt.push_back(lin[i][j]);
            }
            table.push_back(srt);
        }
        if(line_B.size() != str){
            error_120();
            return;
        }
        for(int i=0; i<line_B.size(); ++i){
            B_line.push_back(line_B[i]);
        }
        __init__main();

    }

    Matrix(long long n, long long m, vector<vector<long double>>&lin, vector<vector <long double>>line_B){
        str = n;
        stl = m;
        for(int i=0; i<n; i++){
            srt.clear();
            for(int j=0; j<m; j++){
                srt.push_back(lin[i][j]);
            }
            table.push_back(srt);
        }
        cout<<line_B.size()<<endl;
        vector<long double> a = line_B[0];
        if(line_B.size()!=str || a.size()>=line_B.size()){
            error_120();
            return;
        }
        for(int i=0; i<line_B.size(); ++i){
            B_line.push_back(line_B[0][i]);
        }
        __init__main();
    }

    long double get_determnant(){
        if(calculus){
                return det;
        }
        remember_main();
        calculus=true;
        calculus_det();
        return det;
    }

    void show_inverse_A(){
        remember_main();
        check_have_inA();
        if (have_determanant){
            for(int i=0; i<str; i++){
                for(int j=0; j<stl; j++){
                    printf("%.2Lf ", &inA[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    vector<vector <long double>> get_inverse_A(){
        remember_main();
        check_have_inA();
        return inA;
    }

    void show_E(){
        for(int i=0; i<str; i++){
            for(int j=0; j<stl; j++){
                printf("%.2Lf ", &E[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void show(){
        for(int i=0; i<str; i++){
            for(int j=0; j<stl; j++){
                printf("%.2Lf ", &table[i][j]);
            }
            printf("\n");
        }
    }

    vector<vector<long double>> get_matrix(){
        return main;
    }

    void show_another_matrix(vector<vector<long double>> a){
        vector<long double> p ;
        for(int i=0;i<a.size(); ++i){
            p = a[i];
            for(int j = 0; j<p.size(); ++j){
                printf("%.2Lf ", &p[j]);
            }
            p.clear();
            printf("\n");
        }
    }
    ///Code
    ///0 - standart matrix
    ///1 - inverse matrix
    vector<vector<long double>> multiply(vector<vector <long double>> J, int code){
        cout<<"Now it awailable, but not work)))"<<endl;
        if(code==0){
            __init__table();
        }else if(code==1){
            __init__table_inverse();
        }else{
            cout<<"INCORRECT INPUT, ERROR-189"<<endl;
            return main;
        }

        long long str_n = J.size();
        long long stl_n = J[0].size();
        if(stl!=str_n){
            cout<<"ERROR-853"<<endl;
            return main;
        }
        vector< vector<long double>> new_matrix;
        vector<long double> new_line;
        for(int i=0; i<str; ++i){
            for(int j=0; j<stl_n; ++j){
                long double Z = 0;
                for(int index=0; index<stl; ++index){
                    Z += table[i][index] * table[index][j];
                }
                new_line.push_back(Z);
            }
            new_matrix.push_back(new_line);
            new_line.clear();
        }
        return new_matrix;
    }

    vector<vector<long double>> subtract(vector<vector <long double>> J, int code){
        long long str_n = J.size();
        long long stl_n = J[0].size();
        if(str != str_n || stl != stl_n){
            cout<<"ERROR-574"<<endl;
            return table;
        }
        if(code==1){
            __init__table();
            for(int i=0; i<str; ++i){
                for(int j=0; j<stl; ++j){
                    table[i][j]-=J[i][j];
                }
            }
        }else if(code==0){

            check_have_inA();
            __init__table_inverse();

            for(int i=0; i<str; ++i){
                for(int j=0; j<stl; ++j){
                    table[i][j]-=J[i][j];
                }
            }
            return table;
        }else{
            cout<<"nothing"<<endl;
        }
        return table;
    }
    ///Function for more beutiful cout
    ///1) cout in new format example
    ///write tommorow
    /*
        | a , a , a |
    X = | a , a , a |
        | a , a , a |
    */
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

void show_inverse(Matrix A){
    cout<<endl<<"Inverse Matrix: "<<endl;
    A.show_inverse_A();
}

void main_task(){
    //first
    read_data();
    Matrix a(n, m, input_table);
    a.show();
    cout<<"det(A) = "<<a.get_determnant()<<endl;
    show_inverse(a);

    read_data();
    Matrix b(n, m, input_table);
    b.show();
    cout<<"det(B) = "<<b.get_determnant()<<endl;
    /// - worked
    //a.show_another_matrix(a.subtract(input_table, 0));
    /// * not work
    cout<<"A*B = "<<endl;
    a.show_another_matrix(a.multiply(input_table, 0));
    ///Beutiful console now work

    ///Final test
}

int main()
{
    main_task();
    return 0;
}
