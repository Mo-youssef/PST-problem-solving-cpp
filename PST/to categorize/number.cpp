#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcdR(int a, int b){
    if (b==0) return a;
    return gcdR(b,a%b);
}

int gcdI(int a, int b){
    int t,q;
    for (; b; ){
        //t = a%b;
        q = a/b;
        t = a - q*b;
        a=b;
        b=t;
    }
    return a;
}

vector<int> res;
void divisible(int n){
    int i;
    for (i = 1; i < n/i; i++){
        if(n%i==0){
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    if (n==i*i) res.push_back(i);
    return;
}

bool isPrimef(ll n){
    for (ll i = 2; i<=n/i; i += 1 + (i&1))
        if (n%i == 0) return 0;
    return n!=1;
}

const int N = 10000;
bitset<N> isPrime;
void sieve(){
    isPrime.set();
    for (int i = 2; i<=N/i; i+=1+(i&1))
        for (int j = i*i; j<=N; j+=i)
            isPrime[j] = 0;
}

vector<pair<ll,ll>> factors;
void primeFactors(ll n){
    int p;
    for (int i = 2; i<=n/i; i+=1+(i&1)){
        p = 0;
        while(n%i==0){
            p++;
            n/=i;
        }
        if (p) factors.push_back({i,p});
    }
    if (n!=1) factors.push_back({n,1});
}

int main(){
    ll a;
    while(cin>>a){
        factors.clear();
        primeFactors(a);
        for (int i =0; i<factors.size();i++)
            cout<<factors[i].first<<"  "<<factors[i].second<<endl;
    }
}
