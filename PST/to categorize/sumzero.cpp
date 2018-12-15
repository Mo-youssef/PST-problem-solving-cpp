// sum zero BS
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 2500+5;

int A[N],B[N], C[N], D[N], R[N*N], L[N*N], n, res;

void BS(int a){
    int lo=0, med, hi =(n*n)-1,r;
    while (lo<hi) {
        med = (lo+hi)>>1;
        r = a+R[med];
        if(!r) {
            res++;
            int j = 1;
            while (R[med+j]==R[med]&&j<=hi-med){
                res++;
                j++;
            }
            j=1;
            while (R[med-j]==R[med]&&j<=med){
                res++;
                j++;
            }
            return;
        }
        if(r>0) hi = med;
        else lo = med+1;
    }
}

int main(){
    cin>>n;
    for (int i = 0; i<n;i++)
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    for (int i = 0; i<n;i++)
        for (int j = 0; j<n;j++)
            R[i*n+j] = C[i]+D[j];
    sort(R,R+n*n);
    for (int i = 0; i<n;i++)
        for (int j = 0; j<n;j++){
            L[i*n+j] = A[i]+B[j];
            BS(L[i*n+j]);
        }
    cout<<res;
}
