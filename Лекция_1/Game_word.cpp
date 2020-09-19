#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int a;
char sym[4];

int turn1(){
    printf("\n Turn first player. Write word: ");
    char word[64];
    scanf("%s", &word);
    string ww = word;
    int ch =0;
    for(int i=0;i<a;i++){
        if(ww.find_first_of(sym[i])!=string::npos){
            ch++;
        }
    }
    if(ch != a){
        printf("Not Found Need letter.");
        return -1;

    }else{
        return 1;
    }
}
int turn2(){
    printf("\n Turn second player. Write word: ");
    char word[64];
    scanf("%s", &word);
    string ww = word;
    int ch =0;
    for(int i=0;i<a;i++){
        if(ww.find_first_of(sym[i])!=string::npos){
            ch++;
        }
    }
    if(ch != a){
        printf("Not Found Need letter.");
        return -1;

    }else{
        return 1;
    }
}
int main()
{
    printf("How many numbers will there be? \n");
    scanf("%d", &a);
    srand(time(0));
    for(int i=0;i<a;i++){
       sym[i]='a'+rand() % 22;
       for(int h=0;h<i;h++){
            if(sym[i]==sym[h]){
                i--;
                break;
            }
       }
    }
    for(int i=0;i<a;i++){
        printf("%c " ,sym[i]);
    }
    while(true){
        if(turn1() == 1){
            while(turn2()!=1){}
        }
    }
    return 0;
}
