#include<bits/stdc++.h>
#include<iostream>

using namespace std
const int N = 1e5 + 5;
char pat[N];
int F[N],n;


int getNextLen(int l, char c){
    while(l && pat[l]!=c){
        l = F[l-1];
    }
    if(pat[l] == c)	l++;
	return l;
}

void computeF(){
    F[0] = 0;
    for (int i = 1; i<n;i++){
        F[i] = getNextLen(F[i-1],pat[i]);
    }
}

int main(){
    while(cin>>pat,pat[0]!='*'){
        n = strlen(pat);
        computeF();
        if(n%(n-F[n-1]))	printf("1\n");
        else	printf("%d\n", n/(n-F[n-1]));
    }
}
