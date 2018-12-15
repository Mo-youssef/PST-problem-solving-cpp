#include<iostream>
#include<bits/stdc++.h>

using namespace std;
const int N = 100+5, M = 1e5+5;

int n,r1,c1,r2,c2;
bool vis[N][M];
int dis[N][M], A[N];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int BFS(){
    int d, x, y;
    pair<int,int> node;
    vector<pair<int,int>> q;
    q.push_back({r1,c1});
    dis[r1][c1] = 0;
    vis[r1][c1] = 1;
    for (int k = 0; k < q.size(); ++k){
        node = q[k];
        d = dis[node.first][node.second];
        for (int i = 0; i < 4; i++){
            x = node.first+dx[i];
            y = node.second+dy[i];
            if(x<0) x = 0;
            if(x>=n) x = n-1;
            if(y<0) y = 0;
            if(y>A[x]) y = A[x];
            if(vis[x][y]) continue;
            q.push_back({x,y});
            dis[x][y] = d+1;
            vis[x][y] = 1;
            if (x == r2 && y == c2) return d+1;
        }
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    cin>>n;
    for (int i = 0; i<n; i++){
        cin>>A[i];
    }
    cin>>r1>>c1>>r2>>c2;
    r1--;c1--;r2--;c2--;
    BFS();
    cout<<dis[r2][c2];
}
