#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Z(ll a){
    ll t, res = 0;
    while(a/5>0){
        t = a/5;
        res+=t;
        a=t;
    }
    return res;
}

int main(){
    int n;
    ll N;
    cin>>n;
    while(n--){
        cin>>N;
        cout<<Z(N)<<endl;
    }
}
