#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 1000+5;

double mem[N][N];
int w,b;
double solve(int w1, int b1){
    if (w1==0 || b1<0) return 0;
    if(b1==0) return 1;
    double t = w1 + b1;
    double &ret = mem[w1][b1];
    if (ret==ret) return ret;
    return ret = (w1/t) + (b1/t) *( (b1-1)/(t-1) )*( (w1/(t-2))*solve(w1-1,b1-2) + ((b1-2)/(t-2))*solve(w1,b1-3) );
}

double dp[N][N];
double solve2(){
    dp[0][0] = 0;
    double p1,p2,t;
    for (int i = 1; i<=b; i++) dp[0][i] = 0;
    for (int i = 1; i<=w; i++) dp[i][0] = 1;
    for (int i = 1; i<=w; i++)
        for (int j = 1; j<=b; j++){
            t = i+j;
            if ((b-2)>=0) p1 = (i/(t-2))*dp[i-1][j-2];
            else p1 = 0;
            if ((b-3)>=0) p2 = ((j-2)/(t-2))*dp[i][j-3];
            else p2 = 0;
            dp[i][j] = (i/t) + (j/t) *( (j-1)/(t-1) )*( p1 + p2 );
        }
    return dp[w][b];
}

double dpmr[2][N];
double solve3(){
    dpmr[0][0] = 0;
    double p1,p2,t;
    for (int i = 1; i<=b; i++) dpmr[0][i] = 0;
    for (int i = 1; i<=w; i++){
        dpmr[i%2][0] = 1;
        for (int j = 1; j<=b; j++){
            t = i+j;
            if ((b-2)>=0) p1 = (i/(t-2))*dpmr[(i-1)%2][j-2];
            else p1 = 0;
            if ((b-3)>=0) p2 = ((j-2)/(t-2))*dpmr[i%2][j-3];
            else p2 = 0;
            dpmr[i%2][j] = (i/t) + (j/t) *( (j-1)/(t-1) )*( p1 + p2 );
        }
    }
    return dpmr[w%2][b];
}

int main(){
    memset(mem, -1, sizeof mem);
    cin>>w>>b;
    cout.precision(9);
    cout<<solve(w,b)<<"   "<<solve2()<<"   "<<solve3()<<endl;
}
