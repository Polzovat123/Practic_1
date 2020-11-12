#include <iostream>

using namespace std;

bool zn=false;
bool last;

void write_byte( char number, bool position ){
    for (int i=0;i<8;i++){
        if (( number >> i ) & 1 != 0 || (position == true && zn == true && i==7) )
            printf("%d", 1);
        else
            printf("%d", 0);
    }
}

void write_r_byte( char number, bool position ){
    for (int i=0;i<8;i++){
        if(position == true && zn == true && i==7) {printf("1"); return;}
        if (( number >> i ) & 1 != 0  )
            printf("%d", 0);
        else
            printf("%d", 1);
    }
}

void write_a_byte(char number, bool position){
    for (int i=0;i<8;i++){
        if(last){
            if (( number >> i ) & 1 != 0 || (position == true && zn == true && i==7) ){
                printf("%d", 1);
                last = false;
            }else
                printf("%d", 0);
        }else{
                if(position == true && zn == true && i==7) {printf("1"); return;}
                if (( number >> i ) & 1 != 0  )
                    printf("%d", 0);
                else
                    printf("%d", 1);
        }
    }
}

void write_all_byte(char *number, int len){
    for(int i=0;i<len;i++){
        write_byte(*number++, (i+1)%len==0 );
        printf(" ");
    }
    printf("\n");
}

void write_reverso(char *number, int len){
    for(int i=0;i<len;i++){
        write_r_byte(*number++, (i+1)%len==0 );
        printf(" ");
    }
    printf("\n");
}

void write_additional(char *number, int len){
    last = true;
    for(int i=0;i<len;i++){
        write_a_byte(*number++, (i+1)%len==0 );
        printf(" ");
    }
    printf("\n");
}

void write_info(long long a, int len, char *number){
    printf("Straight code:   ");
    write_all_byte(number, len);
    printf("Reverse code:    ");
    if(!zn)write_all_byte(number,len);else write_reverso(number, len);
    printf("Additional code: ");
    if(!zn)write_all_byte(number,len);else write_additional(number, len);
    printf("Machine code:    ");
    write_all_byte( (char *)&a, len);
}

int main()
{
    int a;
    cin>>a;
    zn = false;
    long long h=a;
    if(a<0){h=abs(a); zn = true;}
    char *number = (char *)&h;
    write_info(a,sizeof(short), number);

    short b;
    cin>>b;
    zn = false;
    h=b;
    if(b<0){h=abs(b); zn = true;}
    char *numberb = (char *)&h;
    write_info(b,sizeof(int), numberb);

    long long c;
    cin>>c;
    zn = false;
    h=c;
    if(c<0){h=abs(c); zn = true;}
    char *numberc = (char *)&h;
    write_info(c,sizeof(long long), numberc);
    return 0;
}
