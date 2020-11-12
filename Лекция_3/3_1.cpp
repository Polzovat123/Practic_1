#include <iostream>

using namespace std;

void write_number(short number){
    for(int i=0;i<15;i++){
        printf("%d", ((abs(number)>>i) & 1) );
        if ((i+1)%4==0)printf(" ");
    }
    if(number>0) printf("0"); else printf("1");
    printf("\n");
}

short index_rename(short number, short i){
    if (i == 16){
        printf("Number: %d ", number*-1);
        write_number(number*-1);
        return number*-1;
    }else{
        short two = 1 << i;
        short zn = number/abs(number);
        write_number(two);
        write_number(number);
        printf("Number_decimal: %d \n", (number ^ (two) ) );
        write_number((number ^ (two) ));
        return (number ^ (two) );
    }
}

int main()
{
    short f;
    short a;
    printf("Write numbers: "); scanf("%d", &f);
    write_number(f);
    while(true){
        printf("\nWrite index rename: ");
        short b=f;
        scanf("%d", &a);
        if (a<0 || a> 16)break;
        f=b;
        f = index_rename(f, a);
    }
    return 0;
}
