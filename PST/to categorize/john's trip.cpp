#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 50+5, M = 2e3+5;
int head[N], to[M], nxt[M], ne, degree[N], vis[M];

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
    memset(degree, 0, sizeof degree);
    memset(vis, 0, sizeof vis);
}
void addEdge(int a, int b){
    nxt[ne] = head[a];
    to[ne] = b;
    head[a] = ne++;
}
void addBiEdge(int a, int b){
    addEdge(a,b);
    addEdge(b,a);
}

int ans[M], vid, sz;
void DFS(int u){
    for (int &k = head[u]; ~k; ){
        int e = k, v = to[k];
        k = nxt[k];
        if(vis[e]==vid) continue;
        vis[e^1] = vid;
        DFS(v);
        ans[sz++] = e>>1;
    }
}

int n, m, a, b, c, mn, imp;
pair<int, pair<int, int>> E[M];
int main(){
   // freopen("i.txt", "rt", stdin);
    while(1){
        int start = -1;
        m=0, n=0, mn=N, sz=0, imp = 0;
        init();
        vid++;
        while(cin>>a>>b, a || b){
            cin>>c;
            E[m++] = {c,{a,b}};
            degree[a]^=1, degree[b]^=1;
            n = max(n, max(a,b));
            start = mn = min(mn, min(a,b));
        }
        if (start == -1) break;
        sort(E,E+m);
        for(int i = m-1; i >= 0; i--)
            addBiEdge(E[i].second.first, E[i].second.second);
        DFS(start);
        int idx = find(degree, degree+N, 1)-degree;
        if (idx!=N) imp = 1;
        if(sz!=m || imp)
            cout<<"Round trip does not exist."<<endl;
        else
            for (int i = sz-1; i >= 0; i--)
                cout<<E[sz-1-ans[i]].first<<" \n"[!i];
        cout<<endl;
    }
}
