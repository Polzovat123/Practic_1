#include <iostream>

using namespace std;

int main()
{
    int s;
    scanf("%d", &s);
    for(int i=0;i<=((s+1)*6-15)/2+1;i++){
        printf("-");
    }
    printf("<Table Pifagor>");
    for(int i=0;i<=((s+1)*6-15)/2;i++){
        printf("-");
    }
    printf("\n|");
    //name string
    for(int i=0;i<=s;i++){
        if(i!=0){printf ("|% 4d|", i-1);}else{
            printf("|----|");
        }
    }
    printf("|\n");
    for(int i=0;i<s;i++){
        printf("|");
        //write column
        printf("|% 4d|",i);
        for(int j=0;j<s;j++){
            printf ("|% 4d|", i*j);
        }
        printf("|");
        printf("\n");
    }
    for(int i=0;i<=(s+1)*6+1;i++){
        printf("-");
    }
    return 0;
}
