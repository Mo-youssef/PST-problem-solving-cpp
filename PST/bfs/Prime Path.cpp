#include <bits/stdc++.h>
#include<math.h>
#include<string>

using namespace std;

const int N = 1e4;

struct node{
    string num;
    int level;
};

int vis[N],l;
string a, a1, a2, a3, a4;
int b;
node n;
vector<node> primes;

bool isPrime(int a){
    if (a%2==0)return 0;
    for (int i = 3; i <= (int) sqrt(a) +1; i+=2 ){
        if ( a % i == 0) return 0;
    }
    return 1;
}

void init(){
    memset(vis, 0, N*sizeof vis[0]);
    primes.clear();
}

int BFS(){
    if (stoi(a)==b) return 0;
    primes.push_back({a,0});
    for (int k = 0; k < primes.size(); ++k){
        n = primes[k];
        a1 = a2 = a3 = a4 = n.num;
        vis[stoi(a1)] = 1;
        l = n.level;
        for(int i=0;i<=9;++i){
            if (i<5) a1[3] = char(2*i + 1) + '0';
            a2[2] = (char) i+ '0';
            a3[1] = (char) i+ '0';
            if (i>0) a4[0] = (char) i + '0';

            if (stoi(a1)==b || stoi(a2)==b || stoi(a3)==b || stoi(a4)==b) return l+1;

            if (!vis[stoi(a1)] && isPrime(stoi(a1))) primes.push_back({a1,l+1});
            if (!vis[stoi(a2)] && isPrime(stoi(a2))) primes.push_back({a2,l+1});
            if (!vis[stoi(a3)] && isPrime(stoi(a3))) primes.push_back({a3,l+1});
            if (!vis[stoi(a4)] && isPrime(stoi(a4))) primes.push_back({a4,l+1});
        }
    }
    return -1;
}

int t;
int main(){
    cin>>t;
    while(t--){
        init();
        cin>>a>>b;
        int ans = BFS();
        if(ans==-1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }
}
// 1 4241 6101

