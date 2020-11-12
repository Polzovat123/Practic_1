#include <iostream>

using namespace std;

bool get_bit(const unsigned char *number, char index){
        return (*number >> ((8 - 1) - index)) & 1;
}


void show(const unsigned char *p) {
        unsigned char mask = 0x80;
        for (int i = 0; i < 7; ++i) {
                printf("%d", get_bit(p, i));
        }
        printf(" ");
}

void module(unsigned char *p, int len) {
        for (int i = 0; i < len; i++) {
                show(p++);
        }
        printf("\n");
}

int main()
{
    printf("Write long double: ");
    unsigned char ld;
    scanf("%g", &ld);
    unsigned char *ldp = &ld;
    module(ldp, sizeof(long double), 4);
    printf("Write double: ");
    unsigned char a;
    scanf("%g", &a);
    unsigned char *p = &a;
    module(p, sizeof(double), 3);
    printf("Write float: ");
    unsigned char aa;
    scanf("%g", &aa);
    unsigned char *pp = &aa;
    module(pp, sizeof(float), 0);
    return 0;
}
//0 10000010 10000011 11010111 0000101
