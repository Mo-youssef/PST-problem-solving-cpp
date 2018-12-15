#include <bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 5e4 + 4, OO = 0x3f3f3f3f;

int head[N], to[N<<1], nxt[N<<1], ne, n, r1, r2, par[N];

void init(){
    memset(head+1, -1, (n+1)*sizeof head[0]);
    ne = 0;
}
void addEdge(int u, int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}
void addBiEdge(int u, int v){
    addEdge(u,v);
    addEdge(v,u);
}

void DFS(int u, int pe){
    for (int k = head[u]; ~k; k = nxt[k]){
        if (k==pe) continue;
        int v = to[k];
        par[v] = u;
        DFS(v, k^1);
    }
}

int main(){
    int a;
    cin>>n>>r1>>r2;
    init();
    for (int i = 1; i<n; i++){
        cin>>a;
        if (i<r1)
            addBiEdge(a,i);
        if (i>=r1)
            addBiEdge(a,i+1);
    }
    DFS(r2,-1);
    for (int i = 1; i<=n; i++){
        if(i==r2) continue;
        cout<<par[i]<<" ";
    }
}
