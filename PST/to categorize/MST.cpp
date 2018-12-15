#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5, M = 1e5 +5, oo=0x3f3f3f3f;

int head[N], to[M], nxt[M], ne, n;
long long cst[M];
void init(){
    memset(head+1, -1, n*sizeof head[0]);
    ne =0;
}
void addEdge(int a, int b, long long c){
    nxt[ne] = head[a];
    to[ne] = b;
    cst[ne] = c;
    head[a] = ne++;
}
void addBiEdge(int a, int b, long long c){
    addEdge(a,b,c);
    addEdge(b,a,c);
}

int dis[N], vis[N], vid;
long long total;
void prim(int src = 0){
    memset(dis,oo,sizeof dis);
    priority_queue<pair<int,int>> q;
    dis[src] = 0;
    q.push({0,src});
    while(q.size()){
        int d = -q.top().first, u = q.top().second;
        q.pop();
        vis[u] = 1;
        if(dis[u] != d)	continue;
        total+=dis[u];
        for (int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            long long c = cst[k];
            if (dis[v]>c && !vis[v]){
                dis[v] = c;
                q.push({-dis[v],v});
            }
        }
    }
    return;
}

int m,a,b,c;
int main(){
    //freopen("i.txt","rt",stdin);
    cin>>n>>m;
    init();
    for (int i = 0; i<m; ++i){
        cin>>a>>b>>c;
        addBiEdge(a,b,c);
    }
    prim(1);
    cout<<total;
}
