#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+5, M = 2e3 + 5, oo = 0x3f3f3f3f, QS = (1<<int(ceil(log(N)/log(2)))), QSM1 = QS-1;
int head[N], to[M], nxt[M], cst[M], ne, n, m;

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
}
void addEdge(int u, int v, int c){
    nxt[ne] = head[u];
    to[ne] = v;
    cst[ne] = c;
    head[u] = ne++;
}

int q[QS], dis[N], inQ[N], vid;

bool bellman(int src){
    memset(dis, oo, sizeof dis);
    int frnt = QSM1, bck = 0, qs = 1;
    dis[src] = 0;
    q[0] = 0;
    inQ[src] = ++vid;
    int x = n;
    while(x-- && qs){
        int s = qs;
        while(s--){
            int u = q[--qs, frnt = ++frnt&QSM1];
            inQ[u] = 0;
            for (int k = head[u]; ~k; k = nxt[k]){
                int v = to[k], c = cst[k];
                int d = dis[u]+c;
                if(dis[v]>d){
                    if(!x) return 0;
                    dis[v] = d;
                    if(inQ[v]!=vid){
                        inQ[v] = vid;
                        q[++qs, ++bck&QSM1] = v;
                    }
                }
            }
        }
    }
    return 1;
}

int t, a, b, c;
int main(){
    //freopen("i.txt","rt",stdin);
    cin>>t;
    while(t--){
        cin>>n>>m;
        init();
        for(int i =0; i<m; ++i){
            cin>>a>>b>>c;
            addEdge(a,b,c);
        }
        if(bellman(0)) cout<<"not possible"<<endl;
        else cout<<"possible"<<endl;
    }
}




