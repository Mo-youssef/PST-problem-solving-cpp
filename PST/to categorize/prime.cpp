#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 +5, M = 2e5 + 5;
int b;

struct node{
    string txt;
    int level;
};

bool isPrime(int num){
    if (num%2==0)return 0;
    for (int i = 3; i <= (int) sqrt(num) +1; i+=2 ){
        if ( num % i == 0) return 0;
    }
    return 1;
}

string a1,a2,a3,a4;
vector<node> nodes;
int vis[N], vid;
int bfs(){
    for (int k = 0; nodes.size(); k++){
        node a = nodes[k];
        a1 = a2 = a3 = a4 = a.txt;
        int l = a.level;
        vis[stoi(a.txt)] = vid;
        for (int i = 0; i<=9; ++i){
            if(i<5) a1[3] = '0' + (2*i+1);
            a2[2] = '0' + i;
            a3[1] = '0' + i;
            if (i>0) a4[0] = '0' + i;

            if(stoi(a1)==b||stoi(a2)==b||stoi(a3)==b||stoi(a4)==b) return l+1;

            if (isPrime(stoi(a1))&& vis[stoi(a1)] != vid) nodes.push_back({a1,l+1});
            if (isPrime(stoi(a2))&& vis[stoi(a2)] != vid) nodes.push_back({a2,l+1});
            if (isPrime(stoi(a3))&& vis[stoi(a3)] != vid) nodes.push_back({a3,l+1});
            if (isPrime(stoi(a4))&& vis[stoi(a4)] != vid) nodes.push_back({a4,l+1});
        }
    }
    return -1;
}

string root;
int main(){
  //  freopen("i.txt","rt",stdin);
    int t;
    cin>>t;
    while(t--){
        vid++;
        nodes.clear();
        cin>>root>>b;
        nodes.push_back({root,0});
        if(stoi(root)==b) {
            cout<<0<<endl;
            continue;
        }
        int ans = bfs();
        if (ans==-1)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;
    }
}
