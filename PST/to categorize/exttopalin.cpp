#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

const int MOD = 1e9 + 7;

const int base = 59;

int main()
{
    string ip;
    while (cin>>ip){
        long long h1,h2, po = base;
        int k = ip.size(), mx = 1, p=1;
        h1 = h2 = (ip[k-1]-'A') % MOD;
        for (int i = k-2; i>=0; i--){
            p++;
            h2 = ((h2*base)%MOD + (ip[i]-'A'))%MOD;
            h1 = (h1 + (po*(ip[i]-'A'))%MOD)%MOD;
            if (h1==h2) mx = p;
            po = (po*base)%MOD;
        }
        for (int i=k-mx-1;i>=0;--i) ip+=ip[i];
        cout<<ip<<"\n";
    }
}
