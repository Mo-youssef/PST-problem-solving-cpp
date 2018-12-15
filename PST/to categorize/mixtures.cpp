#include <bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 1e2 + 5, OO = 0x3f3f3f3f;

long long mem[N][N];
int R[N];
int n;

int summ(int a, int b){
    int ret = 0;
    for (int i = a; i <= b; i++){
        ret+=R[i];
    }
    return ret%100;
}

long long solve(int i = 0, int j = n-1){
	if(i == j)	return 0;
	long long & ret = mem[i][j];
	if(ret != -1)	return ret;
	ret = 1e18;
	for(int k = i ; k < j ; ++k){
		long long cur = solve(i, k) + solve(k+1, j) + summ(i,k) * summ(k+1, j);
		ret = min(ret, cur);
	}
	return ret;
}


int main(){
	while(cin>>n){
        for(int i = 0 ; i < n ; ++i)	cin>>R[i];
        memset(mem, -1, sizeof mem);
        cout<< solve()<<endl;
	}
}

