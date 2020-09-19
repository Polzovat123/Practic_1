#include <iostream>

using namespace std;

int main()
{
    int a,s,ans,s_new;
    printf("Write number and system this number: \n");
    scanf("%d", &a);
    scanf("%d", &s);
    printf("Which system should be transferred: ");
    scanf("%d", &s_new);
    for(int i=1;a>0;i*=s){
        ans += i*(a%10);
        a/=10;
    }
    printf("%d \n",ans);
    int jj;
    for(int i=1; i<=ans; i*=s_new){jj=i;}
    cout<<"el1  "<<endl<<endl;
    bool hh = true;
    for(int i=jj;i>=1;i/=s_new){
        int nn = ans / jj;
        if(hh==true && i==jj && nn ==0){hh=false;}else{printf("%d", nn);hh=false;}
        ans -=nn*jj;
        jj/=s_new;
    }
    return 0;
}
