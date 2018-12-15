#include <bits/stdc++.h>
using namespace std;

struct node{
    string code;
    int step;
    int i;
    int j;
};

int steps, ns;
int di[] = {2,2,-2,-2,1,1,-1,-1};
int dj[] = {1,-1,1,-1,2,-2,2,-2};
string a, b, c, temp;
node n;
vector<node> squares;

void init(){
    steps = ns = 0;
    squares.clear();
}

int BFS(){
    if (! a.compare(b)) return 0;
    squares.push_back({a,0,0,0});
    for (int k = 0; k < squares.size(); ++k){
        n = squares[k];
        temp = n.code;
        steps = n.step;
        for(int i=0;i<8;++i){
            if (char(temp[0]+di[i]) < 'a' || char(temp[1]+dj[i]) < '1' || char(temp[0]+di[i]) > 'h' || char(temp[1]+dj[i]) > '8' || (di[i]==n.i && dj[i]==n.j) ) continue;
            c.clear();
            c.push_back(char(temp[0]+di[i]));
            c.push_back(char(temp[1]+dj[i]));
            ns = steps + 1;
            if (! c.compare(b)) return ns;
            squares.push_back({c,ns,-di[i],-dj[i]});
        }
    }
}

int main(){
    while(cin>>a>>b){
        init();
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<BFS()<<" knight moves."<<endl;
    }
}
