#include <bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 1e2+5;

int n, A[N][N], C[N][N];

int cat(int a[]){
    int sum = 0, mx = 0;
    for (int i=0;i<n; i++){
        sum += a[i];
        if (sum<0) sum = 0;
        if (mx<sum) mx = sum;
    }
    return mx;
}

int cat2D(){
    int s[n];
    int mx=cat(A[0]);
    for (int top = 1; top < n; top++)
        for (int btm = top; btm < n; btm++){
            for (int c = 0; c<n; c++){
                s[c] = C[btm][c] - C[top-1][c];
            }
            mx = max(mx, cat(s));
        }
    return mx;
}

int main(){
    cin>>n;
    for (int i= 0; i<n; i++)
        for (int j= 0; j<n; j++){
            cin>>A[i][j];
            i ? C[i][j]=C[i-1][j]+A[i][j] : C[i][j]=A[i][j];
        }
    cout<<cat2D()<<endl;
}
