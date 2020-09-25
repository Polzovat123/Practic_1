#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int a[15];
int s=15;


void show(){
    for(int i=0;i<s;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void first_step(){
    for(int i=s/2-1;i>-1;i--){
        int n=i;
        while(true){
            show();
            if(a[n]>a[2*n+1]&&a[n]>a[2*n+2]){
                if(a[2*n+1]<a[2*n+2]&&2*n+1<s){
                    swap(a[2*n+1],a[n]);
                    n=2*n+1;
                }else{
                    if(a[2*n+1]>=a[2*n+2]&&2*n+2<s){
                       swap(a[2*n+2],a[n]);
                        n=2*n+2;
                    }else{
                        break;
                    }
                }
            }else{
                if(a[n]>a[2*n+1]&&a[n]<a[2*n+2]){
                    if(2*n+1<s){
                        swap(a[n], a[2*n+1]);
                        n = 2*n+1;
                    }else{
                        break;
                    }
                }else{
                    if(a[n]<a[2*n+1]&&a[n]>a[2*n+2]){
                        if(2*n+2<s){
                            swap(a[n],a[2*n+2]);
                            n = 2*n+2;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
    }
}

void second_step(){
    int y=s;
    for(int i=s-1;i>-1;i--){
        int n =0;
        y--;
        swap(a[0],a[i]);
        while(true){
            show();
            if(a[n]>a[2*n+1]&&a[n]>a[2*n+2]){
                if(a[2*n+1]<a[2*n+2]&&2*n+1<y){
                    swap(a[2*n+1],a[n]);
                    n=2*n+1;
                }else{
                    if(a[2*n+1]>=a[2*n+2]&&2*n+2<y){
                       swap(a[2*n+2],a[n]);
                        n=2*n+2;
                    }else{
                        break;
                    }
                }
            }else{
                if(a[n]>a[2*n+1]&&a[n]<a[2*n+2]){
                    if(2*n+1<y){
                        swap(a[n],a[2*n+1]);
                        n = 2*n+1;
                    }else{
                        break;
                    }
                }else{
                    if(a[n]<a[2*n+1]&&a[n]>a[2*n+2]){
                        if(n*2+2<y){
                            swap(a[n],a[n*2+2]);
                            n = 2*n+2;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }
        show();
        }
    }
}

void heap(){
    first_step();
    second_step();
}

int main()
{
    srand(time(0));
    char aa;
    scanf("%c", &aa);
    if(aa=='y'){
        srand(time(0));
        for(int i=0;i<s;i++){
            a[i] = rand() % 50-25;
        }
    }else{
        scanf("%d", &s);
        for(int i=0; i<s;i++){
            scanf("%d", &a[i]);
        }
    }
    for(int i=0;i<s;i++){
        printf("%d", a[i]);
        printf(" | ");
    }
    printf("\n");
    heap();
    show();
    return 0;
}
