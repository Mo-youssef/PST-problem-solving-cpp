#include<bits/stdc++.h>

using namespace std;

const int N = 2e3+5;

int n, t;
double p, mem[N][N];

double solve(int i = 0, int j = 0){
    if(i==t) return j;
    if(j==n) return j;
    double &ret = mem[i][j];
    if(ret==ret) return ret;
    return ret = (p)*solve(i+1,j+1) + (1-p)*solve(i+1, j);
}

int main(){
    memset(mem,-1,sizeof mem);
    cin>>n>>p>>t;
    cout.precision(8);
    cout<<solve()<<endl;
}
