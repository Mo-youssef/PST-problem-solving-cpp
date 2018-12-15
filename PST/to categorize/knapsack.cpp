#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 501, K = 2e6 +5, oo = 0x3f3f3f3f;

int k,n,W[N],V[N];
int dp[2][K];

int solve(){
//    for (int i = 0; i<=k; i++)
//        dp[0][i] = 0;
    for (int i = 1; i<=n; i++) {
        for (int j = 0; j <= k; j++){
            int &ret = dp[i%2][j];
            ret = dp[(i-1)%2][j];
            if(W[i]<=j) ret = max(ret, dp[(i-1)%2][j-W[i]]+V[i]);
        }
    }
    return dp[n%2][k];
}

int main(){
    cin>>k>>n;
    memset(dp,0,sizeof dp);
    for (int i = 1; i<n+1; i++){
        cin>>V[i]>>W[i];
    }
    cout<<solve();
}
