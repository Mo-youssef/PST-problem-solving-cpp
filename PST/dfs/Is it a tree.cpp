#include<iostream>
#include <bits/stdc++.h>

using namespace std;

#define neig(u, e, v) for(int e = head[u], v ; v = to[e], ~e ; e = nxt[e])

const int N=10000,M=20000;

int head[N], nxt[M], to[M], ne, n, m;
bool vis[N] = {false};
bool istree = true;

void init(){
    memset(head,-1,n*sizeof head[0]);
    ne = 0;
    memset(vis,false, n*sizeof vis[0]);
}

void addEdge(int u, int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}

void addBiEdge(int a, int b){
    addEdge(a, b);
    addEdge(b,a);
}

void DFS(int u, int pe){
    if(vis[u]) {
        istree=false;
        return;
    }
    vis[u] = true;
    for (int k = head[u]; ~k; k = nxt[k]){
        if (k==pe) continue;
        int v = to[k];
        DFS(v,k^1);
    }
}

int main(){
    cin>>n>>m;
    init();
    if (m!=n-1) istree=false;
    int a,b;
    for (int i = 0;i<m;++i){
        cin>>a>>b;
        addBiEdge(a-1,b-1);
    }
    DFS(0,-1);
    for (int i = 0; i<n;++i){
   		if (!vis[i]) istree=false;
    }
    if(istree) cout<<"YES";
    else cout<<"NO";
}
