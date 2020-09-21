#include <iostream>

using namespace std;

int main()
{
    double a1,a2;
    char zn;
    scanf("%lf", &a1);
    scanf("%s",&zn);
    scanf("%lf", &a2);
    switch(zn){
    case '+':
        a1 = a1+a2;
        printf("%g", a1);
        break;
    case '-':
        a1 = a1-a2;
        printf("%g", a1);
        break;
    case '*':
        a1 = a1*a2;
        printf("%g", a1);
        break;
    case '/':
        if(a2!=0){a1 = a1/a2;printf("%g", a1);}else{ printf("Eror");}
        break;
    }
    return 0;
}
