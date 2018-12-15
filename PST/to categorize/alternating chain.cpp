#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

string in;
int n;

int solves(){
    int ret = 0;
    for (int i = 0; i<n; i++){
        if (i%2==0){
            if (isupper(int(in[i]))) ret++;
        }else {
            if (islower(int(in[i]))) ret++;
            }
    }
    return ret;
}
int solvec(){
    int ret = 0;
    for (int i = 0; i<n; i++){
        if (i%2!=0){
            if (isupper(int(in[i]))) ret++;
        }else {
            if (islower(int(in[i]))) ret++;
            }
    }
    return ret;
}

int main(){
    while(cin>>in){
        n = in.size();
        cout<<min(solves(),solvec())<<endl;
    }
}
