#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<map>

using namespace std;

#define neig(u, e, v) for(int e = head[u], v; v = to[e], ~e; e = nxt[e])

const int N=1e4, M=2e4;

int head[N], nxt[M], to[M], ne, n, m, des, vis[N];
vector<int> parID;
int numcity;
bool done =0;
map<char,int> city;

void init(){
    memset(head+1,-1,(m+1)*sizeof head[0]);
    memset(vis+1,0,(m+1)*sizeof vis[0]);
    ne = 0;
    parID.clear();
    numcity = 1;
    done = 0;
    city.clear();
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
    if(u==des) {
            done = 1;
            parID.push_back(u);
            return;
    }
    vis[u]=1;
    neig(u, e, v){
        if (e==pe || vis[v] == 1) continue;
        parID.push_back(u);
        DFS(v, e^1);
        if(done) return;
        parID.pop_back();
    }

}

char numtocity[N];

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d %d", &m, &n);
        init();
        for(int i = 0; i<m; ++i){
            string a,b;
            cin>>a>>b;
            if(!city[a[0]]) {
                    city[a[0]] = numcity++;
                    numtocity[city[a[0]]] = a[0];
            }
            if(!city[b[0]]) {
                    city[b[0]] = numcity++;
                    numtocity[city[b[0]]] = b[0];
            }
            addBiEdge(city[a[0]],city[b[0]]);
        }
        for (int i = 0; i < n; i++){
            done = 0;
            memset(vis+1,0,(m+1)*sizeof vis[0]);
            parID.clear();
            string a,b;
            cin>>a>>b;
            des = city[b[0]];
            DFS(city[a[0]],-1);
            for(int j = 0; j < parID.size(); ++j){
                printf("%c", numtocity[parID[j]]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
