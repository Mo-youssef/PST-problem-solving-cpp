#include<iostream>
#include <bits/stdc++.h>

using namespace std;

#define neig(u, e, v) for(int e = head[u], v ; v = to[e], ~e ; e = nxt[e])

const int N=1e4,M=5e6;

int head[N], nxt[M], to[M], P[N], ne, n;

void init(){
    memset(head+1, -1, n*sizeof head[0]);
    ne = 0;
}
void addEdge(int u, int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}

bool DFS(int u, int score){
    if (score<=0) return 0;
    if (u == n-1) return 1;
    neig(u,e,v){
        if(DFS(v, score+P[v])) return 1;
    }
    return 0;
}

int main(){
    freopen("i.txt","rt", stdin);
    while(cin>>n, ~n){
        init();
        int a, t, p;
        for (int f = 1; f <= n; ++f){
            cin>>p>>a;
            P[f] = p;
            for (int i = 0; i < a; ++i){
                cin>>t;
                addEdge(f,t);
            }
        }
        if(DFS(1,P[1]+100)) cout<<"winnable"<<endl;
        else cout<<"hopeless"<<endl;
    }
}
