#include <iostream>

using namespace std;

int k=1;
void f( char number){
    for (int i=0;i<8;i++){
        if (( number >> i ) & 1 != 0)
            printf("1");
        else
            printf("0");
    }
}
void ww_bb( char *number, int len){
    printf("Module %d : \n", k);
    for(int i=0;i<len;i++){
        f(*number++);
        printf("\n");
    }
    k++;
}

int main()
{
    float a;
    scanf("%f", &a);
    char *p = (char *)&a;
    ww_bb(p,sizeof(float));

    double aa;
    scanf("%g", &aa);
    char *pp = (char *)&aa;
    double answer = *pp;
    ww_bb(pp,sizeof(double));

    long double aaa;
    scanf("%g", &aaa);
    char *ppp = (char *)&aaa;
    ww_bb(ppp,sizeof(long double));
}
