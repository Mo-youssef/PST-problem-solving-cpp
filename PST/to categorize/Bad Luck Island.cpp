#include <bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 1e2+5;

struct res {
    double pr,ps,pp;
    res operator *(double a){
        return {a*pr,a*ps,a*pp};
    }
};

res mem[N][N][N];
bool vis[N][N][N];

res solve(int r, int s, int p){
    double t = r*s+s*p+r*p;
    res p1,p2,p3;
    if (r==0) return {0, 1, 0};
    if (s==0) return {0, 0, 1};
    if (p==0) return {1, 0, 0};
    if (vis[r][s][p]) return mem[r][s][p];
    p1 = solve(r,s,p-1)*((s*p)/t);
    p2 = solve(r-1,s,p)*((r*p)/t);
    p3 = solve(r,s-1,p)*((r*s)/t);
    vis[r][s][p] = 1;
    return mem[r][s][p] = {p1.pr+p2.pr+p3.pr, p1.ps+p2.ps+p3.ps, p1.pp+p2.pp+p3.pp};
}

int main(){
    int r,s,p;
    cin>>r>>s>>p;
    memset(vis, 0, sizeof vis);
    res ss = solve(r,s,p);
    cout.precision(12);
    cout<<ss.pr<<" "<<ss.ps<<" "<<ss.pp<<" "<<endl;
}
