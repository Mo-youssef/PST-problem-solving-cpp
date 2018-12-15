#include <bits/stdc++.h>

using namespace std;

const int N = 30 + 5, M = 900 + 5, OO = 0x3f3f3f3f;
const double EPS = 1e-9;

int n,m;
vector<vector<double>> adjMat;

void solve2(){
	vector<vector<double> > & ret = adjMat;
	for(int k = 0 ; k < N ; ++k)
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < N ; ++j)
				ret[i][j] = max(ret[i][j], ret[i][k] * ret[k][j]);
}

string a, b;
double c;
map<string,int> cur;

int main(){
    int cc = 1;
    while(cin>>n,n){
        adjMat.clear();
        adjMat.resize(N, vector<double>(N, 0));
        int ct = 0;
        cur.clear();
        for (int i = 0; i<n; i++){
            cin>>a;
         //   adjMat[ct][ct] = 1;
            cur[a] = ct++;
        }
        cin>>m;
        for (int i = 0; i<m; i++){
            cin>>a>>c>>b;
            adjMat[cur[a]][cur[b]] = c;
        }
        solve2();
        int j;
        for (j = 0; j < N; j++){
            if(adjMat[j][j]>1){
                cout<<"Case "<<cc<<": "<<"Yes"<<endl;
                break;
            }
        }
        if(j == N) cout<<"Case "<<cc<<": "<<"No"<<endl;
        cc++;
    }
}
