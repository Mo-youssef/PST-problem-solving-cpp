#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 2e2+5, M = 1e3+5;
int head[N], to[M], nxt[M], ne, degree[N];
int ans[M], sz;

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
    memset(degree, 0, sizeof degree);
    sz=0;
}
void addEdge(int a, int b){
    nxt[ne] = head[a];
    to[ne] = b;
    degree[a]++;
    degree[b]--;
    head[a] = ne++;
}

void DFS(int u){
    for (int &k = head[u]; ~k; ){
        int e = k, v = to[k];
        k = nxt[k];
        DFS(v);
        ans[sz++] = e;
    }
}

int m, cnz, cnt1;
string A[M];
int main(){
    freopen("i.txt", "rt", stdin);
    int t;
    char mn = 'z'+1;
    cin>>t;
    while(t--){
        cin>>m;
        cnt1=cnz=0;
        init();
        for (int i = 0; i<m;i++){
            cin>>A[i];
            mn = min(mn, min(A[i][0],A[i].back()));
        }
        sort(A,A+m);
        for(int i=m-1;i>=0;i--){
            addEdge(A[i][0],A[i].back());
        }
        for(int i = 0; i<N; i++){
            if(degree[i]!=0) cnz++;
            if(degree[i] == 1) {
                    mn = i;
                    cnt1++;
            }
        }
        if(cnz){
            if(cnt1!=1) {
                cout<<"***"<<endl;
                continue;
            }
        }
        DFS(mn);
        if (sz!=m) cout<<"***"<<endl;
        else{
            for (int i = sz-1 ; i>=0;i--){
                cout<<A[sz-1-ans[i]]<<".\n"[!i];
            }
        }
    }
}

