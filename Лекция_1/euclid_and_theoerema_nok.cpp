#include <iostream>

using namespace std;

int main()
{
    printf("Write two numbers: ");
    int a,b;
    scanf("%d %d", &a, &b);
    int nok = a*b;
    while(a!=0 && b!=0){
        if(a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }
    a = a +b;
    int *gg = &(a);
    printf("NOD: ");
    printf("%d \n", *gg);// output nod
    nok = nok/a;
    printf("NOK: ");
    printf("%d \n", nok);// output nok
    return 0;
}
