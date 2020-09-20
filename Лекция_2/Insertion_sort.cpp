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
    for(int i=1; i<15;i++){
        for(int j=i;j>0&&a[j-1]>a[j];j--){
            swap(a[j-1],a[j]);
        }
        for(int i=0;i<15;i++){
            printf("%d", a[i]);
            printf(" | ");
        }
        printf("\n");
    }

    return 0;
}
