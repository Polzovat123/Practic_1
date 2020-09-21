#include <iostream>
#include <cmath>

using namespace std;

int convert_input_in_decade_system(string str, int s){
    int number=0;
    //11 8
    int c = 0;
    for(int i=str.length()-1;i>-1;i--){
        switch(str[i]){
            case '0' :
                number += 0*pow(s,c);
                break;
            case '1' :
                number += 1*pow(s,c);
                break;
            case '2' :
                number += 2*pow(s,c);
                break;
            case '3' :
                number += 3*pow(s,c);
                break;
            case '4' :
                number += 4*pow(s,c);
                break;
            case '5' :
                number += 5*pow(s,c);
                break;
            case '6' :
                number += 6*pow(s,c);
                break;
            case '7' :
                number += 7*pow(s,c);
                break;
            case '8' :
                number += 8*pow(s,c);
                break;
            case '9' :
                number += 9*pow(s,c);
                break;
            case 'A' :
                number += 10*pow(s,c);
                break;
            case 'B' :
                number += 11*pow(s,c);
                break;
            case 'C' :
                number += 12*pow(s,c);
                break;
            case 'D' :
                number += 13*pow(s,c);
                break;
            case 'E' :
                number += 14*pow(s,c);
                break;
            case 'F' :
                number += 15*pow(s,c);
                break;
            case 'G' :
                number += 16*pow(s,c);
                break;
            case 'H' :
                number += 17*pow(s,c);
                break;
            default:
                printf("You entered incorrect data.");
                return -1;

        }
        c++;
    }
    return number;
}

int main()
{
    int s,ans,s_new;
    char aa[50];
    printf("Write number and system this number: \n");
    scanf("%s", &aa);
    scanf("%d", &s);
    string h = aa;
    int a=convert_input_in_decade_system(h,s);
    printf("Which system should be transferred: ");
    scanf("%d", &s_new);
    if(s_new<2)return 0;
    int jj;
    for(int i=1; i<=a; i*=s_new){jj=i;}
    bool hh = true;
    for(int i=jj;i>=1;i/=s_new){
        int nn = a / jj;
        if(hh==true && i==jj && nn ==0){hh=false;}else{if(nn<10){printf("%d", nn);}else{char v = 'A'+(nn-10);printf("%c",v);}hh=false;}
        a -=nn*jj;
        jj/=s_new;
    }
    return 0;
}
