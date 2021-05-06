#include <iostream>
#include <ctime>

using namespace std;

int n, ans=0;
int n_helper=0;
int A[100][100];
int B[100][100];
int N[100][100];
bool MYCONST = true;

void get_answer(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(A[i][j]!=B[i][j]){
                int o = i;
                printf("%i -> %i: %i\n\t", o, j, A[o][j]);
                printf("%i -> ", o);
                while(A[o][j]!=B[o][j] && A[o][j]){
                    for(int k=0; k<n; ++k){
                        if(k!=i && k!=j && B[o][k] && A[o][j]==B[o][k]+A[k][j]){
                            printf("%i -> ", k);
                            o=k;
                            break;
                        }
                    }
                }
                printf("%i\n", j);
            }
        }
    }
}

void read_data(){
    printf("Write n: ");
    scanf("%i", &n);
    printf("Задать значения элементов матрицы А вручную (0) или случайным образом (1):");
    scanf("%i", &ans);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            N[i][j] = i;
        }
    }
    if(!ans){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                scanf("%i", &A[i][j]);
                if(A[i][j]<0 || A[i][j]==0)A[i][j] = 0;
                B[i][j] = A[i][j];
            }
        }
    }else{
        srand(time(0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i!=j)A[i][j] = rand()%20+1;
                else
                    A[i][j]=0;
                B[i][j] = A[i][j];
                N[i][j] = i;
            }
        }
    }
}

void draw_matrix_A(){
    printf(" \\ ");
    for(int i=0; i<n; ++i){
        printf("|%03i", i+1);
    }
    printf("|\n");
    for(int i=0; i<n; ++i){
        for(int k=0; k<(1+n)*4; ++k){
            printf("-");
        }
        printf("\n");
        printf("%03i|", i+1);
        for(int j=0; j<n; ++j){
            if(A[i][j]!=0)printf("%03i|", A[i][j]);
            else printf("inf|");
        }
        printf("\n");
    }
}
///can delete
void simple_draw(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(A[i][j]!=0)printf("%i ", A[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
}

void m_with_text(string text){
    printf(text.c_str());
    printf("\n");
    if(MYCONST)draw_matrix_A();
    else simple_draw();
}

void Floid_search(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<n; ++k){
                if(i!=k)
                if((A[i][j]+A[j][k]<A[i][k])||(A[i][k] == 0 && A[i][j]+A[j][k]!=0)){
                    if(A[i][j]!=0 && A[j][k]!=0)
                        A[i][k] = A[i][j]+A[j][k];
                        N[i][k] = N[j][k];
                }
            }
        }
    }
}

void Floid_answer(){
    m_with_text("Исходная матрица: ");
    for(int i=0; i<n; ++i   ){
        Floid_search();
    }
    m_with_text("Матрица кратчайших расстояний: ");
    get_answer();
}


int main()
{
    setlocale(LC_ALL, "Russian");
    read_data();
    Floid_answer();
    return 0;
}
