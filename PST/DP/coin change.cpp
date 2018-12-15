#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+5, M = 1e4;

int V[] = {1, 5, 10, 25, 50};
int n = 5, value, m;
//long long mem[6][N];
//
//int solve(int l, int val){
//    if (val == 0) return 1;
//    if (val < 0) return 0;
//    if (l < 0) return 0;
//    long long &ret = mem[l][val];
//    if (~ret) return ret;
//    return ret = solve(l-1, val) + solve(l, val-V[l]);
//}

long long dp[6][N];
long long solve2(){
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= value; ++j){
            dp[i][j] = dp[i-1][j];
            if (j >= V[i-1]) dp[i][j] += dp[i][j-V[i-1]];
        }
    }
    return dp[n][value];
}

int main(){
    value = 7489;
    solve2();
    while(cin>>m){
        cout<<dp[n][m]<<endl;
    }
}

