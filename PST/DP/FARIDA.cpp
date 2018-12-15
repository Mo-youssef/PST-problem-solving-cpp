#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5, K = 1e9;
int n, P[N];
long long mem[N];

void init(){
    memset(P,0,n*sizeof P[0]);
    memset(mem,-1,n*sizeof mem[0]);
}

long long solve(int l, int g){
    if (l<0) return 0;
    long long &ret = mem[l];
    if (~ret) return ret;
    ret = solve(l-1,g);
    ret = max(ret, solve(l-2,g+P[l])+P[l]);
    return ret;
}

int t,r;
int main(){
    cin>>t;
    for (int tt = 1; tt<=t;++tt){
        cin>>n;
        init();
        for (int i =0; i<n; ++i){
            cin>>r;
            P[i] = r;
        }
        cout<<"Case "<<tt<<": "<<solve(n-1,0)<<endl;
    }
}

