#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 100+5, K = 1000+5;
int n,k, FU[N], mem[N][K];

void init(){
    memset(FU,0,n*sizeof FU[0]);
    memset(mem,-1,sizeof mem);
}

int solve(int l, int rem){
    if (rem == 0) return 0;
    if (l<0) return 0;
    int &ret = mem[l][rem];
    if (~ret) return ret;
    ret = solve(l-1,rem);
    if (FU[l]<=rem) ret = max(ret, solve(l-1,rem-FU[l])+FU[l]);
    return ret;
}

int t;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        init();
        int r;
        int a;
        for (int i =0; i<n; ++i){
            cin>>r;
            for (int j = 0; j<r; ++j){
                cin>>a;
                FU[i] += a;
            }
        }
        cout<<solve(n-1,k)<<endl;
    }
}
