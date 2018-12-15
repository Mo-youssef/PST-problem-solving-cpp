#include <bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 1e6+5, K = 30;

int n,k;
int vis[2][K];
char door[N];

int main(){
    memset(vis, -1, sizeof vis);
    cin>>n>>k;
    bool flag = true;
    int idx;
    for (int i = 0; i <n;i++){
        cin>>door[i];
        idx = (int) door[i]-'A';
        if(vis[0][idx]==-1){
            vis[0][idx] = i;
        }
        if(vis[0][idx]!=-1){
            vis[1][idx] = i;
        }
    }
    k--;
    if (vis[1][0] == 0) k++;
    for (int i = 1; i <n;i++){
        idx = (int) door[i]-'A';
        if (vis[0][idx] == i)
            k--;
        if (k<0) flag = false;
        if (vis[1][idx] == i)
            k++;
    }
    if (flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
