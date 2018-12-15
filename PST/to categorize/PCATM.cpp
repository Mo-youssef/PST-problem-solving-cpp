#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 +5, M = 5e5 +5;

int n, m, vis[N];

bool sol;
int t, a, b;
pair<int,int> E[M];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(vis, -1, n*sizeof vis[0]);
        sol = 1;
        for(int j = 0; j<m; ++j){
            cin>>a>>b;
            E[j].first = a;
            E[j].second = b;
            if(vis[a]==-1 && vis[b]==-1){
                vis[a] = 0;
            }else if(vis[a]==-1){
                vis[a] = 1-vis[b];
            }
            if(vis[b]==-1){
                vis[b] = 1-vis[a];
            }
            if (vis[b]==1-vis[a])
                cout<<"YES"<<endl;
            else{
                sol = 0;
                cout<<"NO"<<endl;
            }
        }
    }
}

