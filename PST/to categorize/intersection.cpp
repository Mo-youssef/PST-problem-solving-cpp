#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
typedef long long ll;

typedef complex<double> point;
typedef tuple<ll,ll,ll> line;
#define X real()
#define Y imag()
#define vec(a, b) ((b)-(a))
#define rotate(p,t) (p)*exp(point(0,t))
#define cross(a, b) ((conj(a)*(b)).imag())
#define dot(a, b) ((conj(a)*(b)).real())
#define len2(v)  dot((v), (v))
#define same(a, b)  (!dCMP(len2(vec(a, b)), 0))

line getLine(const point& p1, const point& p2){
    ll a = p2.Y - p1.Y;
    ll b = -(p2.X - p1.X);
    ll c = -a*p1.X - b*p1.Y;
    return line(a,b,c);
}

int dCMP(const double& a, const double& b){
  if(fabs(a-b) < EPS) return 0;
  return (a>b)*2-1;
}

int ccw(const point& a, const point& b, const point& c){
  point ab = vec(a, b);
  point ac = vec(a, c);
  double d = cross(ab, ac);
  int cmp = dCMP(d, 0);
  if(cmp) return cmp;
  if(same(c, a))  return -3;        //c--b
  if(same(c, b))  return 3;         //a--c
  d = dot(ab, ac);
  if(dCMP(d, 0) < 0)  return -2;    //c--a--b
  point ba = vec(b, a);
  point bc = vec(b, c);
  d = dot(ba, bc);
  if(dCMP(d, 0) < 0)  return 2;     //a--b--c
  return 0;                         //a--c--b
}

int lx1,lx2,ly2,ly1,x1,y1,x2,y2;
int f1,f2,f3,f4;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>lx1>>ly1>>lx2>>ly2>>x1>>y1>>x2>>y2;
        point l1(lx1,ly1),l2(lx2,ly2),r1(x1,y1),r2(x2,y2),r3(x1,y2),r4(x2,y1);
        f1 = ccw(l1,l2,r1);
        f2 = ccw(l1,l2,r2);
        f3 = ccw(l1,l2,r3);
        f4 = ccw(l1,l2,r4);
        if(f1*f2*f3*f4 > 0) cout<<"F"<<endl;
        else cout<<"T"<<endl;
    }
}
