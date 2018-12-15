#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 100000;

int main(){
    int t,n,last,c = 1;
    pair<int,int> A[N];
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 0; i<n;i++){
            cin>>A[i].second>>A[i].first;
        }
        sort(A,A+n);
        last = 0;
        c=1;
        for (int i = 1; i<n;i++){
            if (A[i].second >= A[last].first){
                last = i;
                c++;
            }
        }
        cout<<c<<endl;
    }
}
