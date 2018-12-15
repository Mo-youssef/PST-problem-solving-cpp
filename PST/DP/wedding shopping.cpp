#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int M = 200+5, C = 20+5, K = 20+5;
struct items{
    int cost, nxt, cat;
};

int m, c, cc, k, t,cost,idx,a;
items item[C*K];
int mem[C*K][M];

void init(){
    memset(mem,-1,sizeof mem);
    idx = 0;
   // memset(item,0,sizeof item);
}

int solve(int l, int rem){
    if(l<0) return 0;
    if(rem == 0 && cc == 0) return 0;
    else if(rem == 0 && cc > 0) return -10000;
    int &ret = mem[l][rem];
    if(ret>=0) return ret;
    if(item[l].nxt > 1) ret = solve(l-1,rem);
    else ret = -10000;
    if (item[l].cost<=rem) {
            cc--;
            ret = max(ret, solve(l-item[l].nxt, rem-item[l].cost) + item[l].cost);
            cc++;
    }
    return ret;
}

void print(int l, int rem){
    if(l<0) return;
    if(rem==0) return;
    int ret = solve(l,rem);
    if(ret == solve(l-item[l].nxt, rem-item[l].cost) + item[l].cost) {
        print(l-item[l].nxt, rem-item[l].cost);
        cout<<item[l].cost<<" ";
    }else print(l-1,rem);
}

int main(){
    cin>>t;
    while(t--){
        cin>>m>>c;
        init();
        for(int i = 0; i<c; i++){
            cin>>k;
            for(int j = 1; j<=k; ++j){
                cin>>cost;
                a = idx++;
                item[a].cost = cost;
                item[a].nxt = j;
                item[a].cat = i+1;
            }
        }
        cc = c;
        int sol = solve(idx-1, m);
        if(sol<0) cout<<"no solution"<<endl;
        else cout<<sol<<endl;
//        print(idx-1,m);
    }
}
