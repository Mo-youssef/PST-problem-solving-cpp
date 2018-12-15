#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 2000 +5, M = 2e6 +5;

int head[N], nxt[M], to[M], ne, n, m, vis[N];

void init(){
    memset(head+1,-1,(n)*sizeof head[0]);
    memset(vis+1,-1, (n)*sizeof vis[0]);
    ne = 0;
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

bool DFS(int u, int c){
    if (vis[u]!=-1) return c == vis[u];
    vis[u] = c;
    for (int k =head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(!DFS(v,1-c)) return 0;
    }
    return 1;
}

int scen, a, b;
int main(){
    cin>>scen;
    for (int t = 1; t<= scen;t++){
        cin>>n>>m;
        init();
        for(int j = 0; j<m; ++j){
            cin>>a>>b;
            addBiEdge(a,b);
        }
        int i;
        cout<<"Scenario #"<<t<<":"<<endl;
        for(i =1; i<=n; ++i){
                if(vis[i]==-1){
                    if(!DFS(i, 0)) {
                            cout<<"Suspicious bugs found!"<<endl;
                            break;
                    }
                }
        }
        if (i > n) cout<<"No suspicious bugs found!"<<endl;
    }
}
