#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}

int main(){
    int a,b,ta,tb,g,res = 1;
    cin>>a>>b;
    int q,l,h,flag = 0;
    cin>>q;
    while(q--){
        cin>>l>>h;
        ta = a; tb = b;
        g = gcd(ta,tb);
        while (g>1){
            if (res>=l && res<=h) flag = 1;
            res *= g;
            if (res>=l && res<=h && flag) ta=ta;
            else if (flag){
                res/=g;
                break;
            }
            ta /= g; tb /= g;
            g = gcd(ta,tb);
        }
        if (res>=l && res<=h)
            cout<<res<<endl;
        else cout<<-1<<endl;
    }
}
