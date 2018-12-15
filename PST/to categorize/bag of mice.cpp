#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1005;
int w, b;
double dp[N][N];
double solve(){
	for(int i = 0; i <= w; i++)
		dp[i][0] = 1;
	for(int i = 0; i <= b; i++)
		dp[0][i] = 0;
	dp[0][0] = 0;
	for(int ii = 1; ii <= w; ii++)
		for(int jj = 1; jj <= b; jj++)
		{
			double i = ii, j = jj;
			dp[ii][jj] = i / (i+j);
			if(j>=3)
			dp[ii][jj] += dp[ii][jj-3] * j / (i+j) * (j-1) / (i+j-1) * (j-2) / (i+j-2);
			if(j>=2 &&i>=1)
			dp[ii][jj] += dp[ii-1][jj-2] * j / (i+j) * (j-1) / (i+j-1) * i / (i+j-2);
		}
	return dp[w][b];
}
int main (){
	while(cin>>w>>b){
		printf("%.10f\n", solve());
	}
	return 0;
}
