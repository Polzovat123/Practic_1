#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int a[15];

int main()
{
    char aa;
    scanf("%c", &aa);
    if(aa=='y'){
        srand(time(0));
        for(int i=0;i<15;i++){
            a[i] = rand() % 50 - 25;
        }
    }else{
        for(int i=0; i<15;i++){
            scanf("%d", &a[i]);
        }
    }
    for(int i=0;i<15;i++){
        printf("%d", a[i]);
        printf(" | ");
    }
    printf("\n");
    for(int i=0; i<15;i++){
        for(int j=1;j<=15-i;j++){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
        for(int i=0;i<15;i++){
            printf("%d", a[i]);
            printf(" | ");
        }
        printf("\n");
    }
    return 0;
}
