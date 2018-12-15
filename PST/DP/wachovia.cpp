#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 50+5, K = 1000+5;
int n,k, P[N], W[N], mem[N][K];

void init(){
    memset(W,0,n*sizeof W[0]);
    memset(P,0,n*sizeof P[0]);
    memset(mem,-1,sizeof mem);
}

int solve(int l, int rem){
    if (rem == 0) return 0;
    if (l<0) return 0;
    int &ret = mem[l][rem];
    if (~ret) return ret;
    ret = solve(l-1,rem);
    if (W[l]<=rem) ret = max(ret, solve(l-1,rem-W[l])+P[l]);
    return ret;
}

int t;
int main(){
    cin>>t;
    while(t--){
        cin>>k>>n;
        init();
        int a,b;
        for (int i =0; i<n; ++i){
            cin>>a>>b;
            W[i] = a;
            P[i] = b;
        }
        cout<<"Hey stupid robber, you can get "<<solve(n-1,k)<<"."<<endl;
    }
}

