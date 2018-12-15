#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 4e3 +5, oo = 0x3f3f3f3f;

int V[3], mem[3][N];
int solve(int l, int v){
    if (l<0 && v!=0) return -oo;
    if (v<=0) return 0;
    if (l<0) return 0;
    int &ret = mem[l][v];
    if(~ret) return ret;
    ret = solve(l-1,v);
    if (V[l]<=v){
        ret = max(ret, solve(l,v-V[l]) + 1);
    }
    return ret;
}

int n;
int main(){
    cin>>n>>V[0]>>V[1]>>V[2];
    memset(mem, -1, sizeof mem);
    cout<<solve(2,n);
}
