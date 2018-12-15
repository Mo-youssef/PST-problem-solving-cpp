#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

int n,m,vis[N][N], res[30], dx[]={0,0,-1,1}, dy[]={1,-1,0,0},vid;
char mp[N][N];

void init(){
    memset(res, 0, sizeof res);
    vid++;
}

void BFS(int r, int c){
    pair<int,int> node;
    queue<pair<int,int>> q;
    q.push({r,c});
    vis[r][c]=vid;
    while(q.size()){
        node = q.front();
        q.pop();
        int x = node.first, y = node.second,nx,ny;
        for (int i = 0; i<4; i++){
            nx = x+dx[i]; ny = y+dy[i];
            if (nx<n && ny<m && vis[nx][ny]!=vid && mp[nx][ny]==mp[x][y]){
                q.push({nx,ny});
                vis[nx][ny]=vid;
            }
        }
    }
}

vector<pair<int,int>> fres;

int main(){
    int t;
    cin>>t;
    for (int tt = 1; tt<=t; tt++){
        init();
        fres.clear();
        cin>>n>>m;
        for (int i =0; i<n;i++)
            for (int j =0; j<m;j++)
                cin>>mp[i][j];
        for (int i =0; i<n;i++)
            for (int j =0; j<m;j++)
                if (vis[i][j]!=vid){
                    BFS(i,j);
                    res[(int) mp[i][j]-'a']++;
                }
        for (int i =0; i<30;i++)
            if (res[i]!=0)
                fres.push_back({-res[i],i});
        sort(fres.begin(),fres.end());
        cout<<"World #"<<tt<<endl;
        for (int i = 0; i<fres.size(); i++)
            cout<<char (fres[i].second+'a')<<": "<<-fres[i].first<<endl;
    }
}
