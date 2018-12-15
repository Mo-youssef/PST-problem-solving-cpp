#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+5, M = 5e5+5, OO = 0x3f3f3f3f;

int main(){
  double x = 4.7;
  //x *= 100;
  unsigned long long & y = * ((unsigned long long *) &x);
  cout<<&x<<endl;
  cout<<&y<<endl;
  for(int i = 63 ; ~i ; --i){
    cout << ((y>>i)&1);
    if(i==63 || i == 63-11) cout << " ";
  }
  cout << endl;
  return 0;
}
