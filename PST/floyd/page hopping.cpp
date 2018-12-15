#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5, M = 1e4 +5, oo = 0x3f3f3f3f;
int adjMat[N][N], vis[N], vid, n;

void floyd(){
    for (int k = 1; k < N; k++)
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
}

int main(){
   // freopen("i.txt","rt",stdin);
    int a, b, sum = 0, t = 0;
    double res;
    while (cin>>a>>b, a){
        vid++;
        memset(adjMat, oo, sizeof adjMat);
        sum = 0;
        n = 2;
        adjMat[a][b] = 1;
        vis[a] = vid;
        vis[b] = vid;
        while(cin>>a>>b, a) {
                if (vis[a]!=vid){
                    n++;
                    vis[a] = vid;
                }
                if (vis[b]!=vid){
                    n++;
                    vis[b] = vid;
                }
                adjMat[a][b] = 1;
        }
        floyd();
        for (int i = 1; i < N; ++i)
            for (int j = 1; j < N; ++j){
                if (i!=j){
                    if (adjMat[i][j]<oo){
                        sum+=adjMat[i][j];
                        res = 1.0*sum / (n*(n-1));
                    }
                }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",++t,res);
    }
}
