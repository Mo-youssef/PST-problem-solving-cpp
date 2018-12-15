#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 5, M = 1e4 + 5, OO = 0x3f3f3f3f;
struct edge{
	int f, t, c;
	bool operator <(const edge & e) const{
		return c < e.c;
	}
}E[M];

int n, p, m, x;
int par[N];

void init(){
	iota(par, par+n, 0);
}

int find(int u){
	return (par[u] == u ? u : par[u] = find(par[u]));
}

inline void join(int a, int b){
	a = find(a), b = find(b);
	if(a == b)	return;
	par[b] = a;
}

inline bool sameSet(int a, int b){
	return find(a) == find(b);
}

int t,total;

int main(){
	cin>>t;
	int a,b,c;
	while(t--){
        cin>>p>>n>>m;
        init();
        for(int i = 0 ; i < m ; ++i){
            cin>>a>>b>>c;
            E[i] = {a-1, b-1, p*c};
        }
        sort(E, E+m);
        for(int i = 0 ; i < m ; ++i){
            if(!sameSet(E[i].f, E[i].t)){
                join(E[i].f, E[i].t);
                total += E[i].c;
            }
        }
        printf("%d\n", total);
	}
}

