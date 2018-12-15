#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+5, K = 1e2 +5, oo = 0x3f3f3f3f;

int n, k, V[N];
int mem[N][K];

bool solve(int l, int sm){
    if (l==n-1 && sm%k == 0) return 1;
    else if (l==n-1 && sm%k != 0) return 0;
    int &ret = mem[l][sm];
    if(~ret) return ret;
    return ret = solve( l+1 , abs(sm+V[l+1]%k)%k ) || solve( l+1 , abs(sm-V[l+1]%k)%k );
}

int main(){
   // freopen("i.txt","rt",stdin);
    int t;
    cin>>t;
    while(t--){
        memset(mem, -1, sizeof mem);
        cin>>n>>k;
        for (int i = 0; i<n; i++){
            cin>>V[i];
        }
        if(solve(0,abs(V[0]%k))) cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }
}

//1 5 9 -5 -4 2 -2 0
