#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 10 + 5, M = 20 + 5;
int n, S[N], mem[N];

int solve(int idx){
    int &ret = mem[idx];
    if(~ret) return ret;
    ret = 1;
    for (int pre = 0; pre < idx; pre++)
        if (S[pre]<S[idx])
            ret = max(ret, solve(pre)+1);
    return ret;
}

int maxi;
int main(){
    cin>>n;
    memset(mem,-1,sizeof mem);
    for (int i = 0; i<n;i++) cin>>S[i];
    for (int i = 0; i<n;i++){
        int ret = solve(i);
        if (ret>maxi)
            maxi = ret;
    }
    cout<<maxi;
}
