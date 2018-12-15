#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+5, M = 1e6 +5, oo=0x3f3f3f3f;
int n, par[N], ne;

void init(){
    ne = 0;
    iota(par+1,par+n+1,1);
}

struct edge{
    int f,t,c;
    bool operator <(const edge &e) const{
        return c<e.c;
    }
}E[M];

int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void join(int a, int b){
    a = find(a), b = find(b);
    if (a==b) return;
    par[a] = b;
}
inline bool sameSet(int a, int b){
    return find(a) == find(b);
}

int t, r, v, c;
long long total;
string s;
int main(){
    //freopen("i.txt","rt",stdin);
    cin>>t;
    while(t--){
        cin>>n;
        init();
        total = 0;
        for (int i = 1; i <= n; ++i){
            cin>>s;
            cin>>r;
            for(int j = 0; j<r;++j){
                cin>>v>>c;
                E[ne++] = {i,v,c};
            }
        }
        sort(E,E+ne);
        for (int i = 0; i < ne; ++i){
            if(!sameSet(E[i].f, E[i].t)){
                join(E[i].f, E[i].t);
                total+=E[i].c;
            }
        }
        cout<<total<<endl;
    }
}
