#include <iostream>
#include <cmath>
#include <assert.h>

bool check(long long challenger, int n){
    long long b_Z = 0;
    long long e_Z = 0;
    for(int i=0; i<n; ++i){
        b_Z += challenger%10;
        challenger /= 10;
    }
    for(int i=0; i<n; ++i){
        e_Z += challenger%10;
        challenger /= 10;
    }
    if(b_Z==e_Z){
        return true;
    }
    return false;
}

int main()
{
    int ans=0;
    int n;
    std::cin>>n;
    long long max_ = pow(10, 2*n);
    for(long long i = pow(10, 2*n - 1); i < max_; ++i){
        if(check(i, n)){
            ++ans;
        }
    }
    printf("%i", ans);
    return 0;
}
