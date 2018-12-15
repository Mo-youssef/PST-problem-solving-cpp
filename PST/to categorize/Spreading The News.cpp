#include <bits/stdc++.h>

using namespace std;

const int N = 2500+5, M  = N*N;

int head[N], nxt[M], to[M], ne, n, day[N], mx, md, vis[N];

void init(){
    memset(head, -1, n*sizeof head[0]);
    memset(vis, 0, n*sizeof vis[0]);
    memset(day, 0, n*sizeof day[0]);
    ne = 0;
    mx = 0;
    md = 0;
}
void addEdge(int u, int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}

struct node{
    int num, dis;
};

void BFS(int src){
    node nn;
    int u, d;
    vector<node> q;
    q.push_back({src,0});
    vis[src] = 1;
    for (int k=0; k<q.size()&&d<n+1; k++){
        nn = q[k];
        u = nn.num;
        d = nn.dis;
        for (int e = head[u]; ~e; e = nxt[e]){
            int v  = to[e];
            if (vis[v]) continue;
            vis[v] = 1;
            q.push_back({v,d+1});
            day[d+1]++;
            if(day[d+1]>mx){
                mx = day[d+1];
                md = d+1;
            }
        }
    }
}

int main(){
    int m,a,t;
    cin>>n;
    init();
    for (int i = 0; i<n; i++){
        cin>>m;
        while(m--){
            cin>>a;
            addEdge(i,a);
        }
    }
    cin>>t;
    while(t--){
        memset(day, 0, n*sizeof day[0]);
        memset(vis, 0, n*sizeof vis[0]);
        mx = 0;
        md = 0;
        cin>>a;
        BFS(a);
        if(mx) cout<<mx<<" "<<md<<endl;
        else cout<<0<<endl;
    }
}
