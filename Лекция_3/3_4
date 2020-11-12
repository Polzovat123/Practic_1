#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int n;
ofstream out("output.txt");
vector <char> all;

int main()
{
    cin>>n;
    vector<int> all;
    for(int i=0;i<(n/8)+3;i++){
        int s=0;
        for(int i=0;i<=34;i++){
            s |= (1 << i);
        }
        all.push_back(s);
    }
    int h = all[0];
    h |= (1 << 0);
    h |= (1 << 1);
    all[0] = h;
    for (int i=2; i<=n; ++i){
        int element = all[floor(i/32)];
        if (element & (1 << int(i - (int)floor(i/32)))) {
            if (i <= n){
                for (int j=i+i; j<=n; j+=i){
                    int h = all[floor(j/32)];
                     h &= ~(1 <<  (j - (int)floor(j/32)) );
                     all[floor(j/32)] = h;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        int element = all[floor(i/32)];
        if (element & (1 << int(i - (int)floor(i/32)))) out<<i<<" ";
        if ((i+1)%100==0) out<<endl;
    }
    return 0;
}
