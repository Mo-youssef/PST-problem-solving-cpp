#include<iostream>
#include <bits/stdc++.h>

using namespace std;

#define neig(u, e, v) for(int e = head[u], v ; v = to[e], ~e ; e = nxt[e])

const int N = 5e4 + 5 , M = 1e5 +5 ;

int head[N], nxt[M], to[M], weight[M], ne, n, sum, maxi, node;

void init(){
    memset(head+1,-1,n*sizeof head[0]);
    ne = 0;
    maxi = sum = 0;
}

void addEdge(int u, int v, int w){
    nxt[ne] = head[u];
    to[ne] = v;
    weight[ne] = w;
    head[u] = ne++;
}

void addBiEdge(int a, int b, int w){
    addEdge(a, b, w);
    addEdge(b, a, w);
}

void DFS(int u, int pe){
    if (sum > maxi) {
            node = u;
            maxi = sum;
    }
    neig(u, e, v){
        if (e==pe) continue;
        sum += weight[e];
        DFS(v,e^1);
        sum -= weight[e];
    }
}

int t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        int a,b,w;
        for (int i = 0; i < n-1; ++i){
            scanf("%d %d %d",&a, &b, &w);
            addBiEdge(a,b,w);
        }
        DFS(1,-1);
        maxi = 0;
        DFS(node,-1);
        printf("%d\n", maxi);
    }
}
