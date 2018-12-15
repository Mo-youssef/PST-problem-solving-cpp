#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

typedef long long ll;
typedef complex<double> point;
typedef pair<point,point> segment;
typedef tuple<ll,ll,ll> line;
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).Y)
#define dot(a,b) ((conj(a)*(b)).X)
#define colliner(a, b, p) (!dCMP(cross(vec((a), (b)), vec(a, p)), 0))

inline int dCMP(const double& a, const double& b){
    if(fabs(a-b)<EPS) return 0;
    return (a>b)*2-1;
}

line getLine(segment s){
    ll a,b,c;
    a = s.second.Y - s.first.Y;
    b = s.first.X - s.second.X;
    c = -a*s.first.X - b*s.first.Y;
    return line(a,b,c);
}

bool intline(const line& l1, const line& l2, double & x, double & y){
    point p1(get<0>(l1),get<1>(l1)), p2(get<0>(l2),get<1>(l2));
    ll deno = cross(p1,p2);
    p1 = point(get<1>(l1), get<2>(l1)), p2 = point(get<1>(l2), get<2>(l2));
    ll num1 = cross(p1, p2);
    x = num1*1.0/deno;
    p1 = point(get<0>(l1), get<2>(l1)), p2 = point(get<0>(l2), get<2>(l2));
    ll num2 = cross(p2, p1);
    y = num2*1.0/deno;
    return (deno || (!num1 && !num2));
}

inline bool onRay(point a, point b, point c){
    return dot(vec(a,b),vec(a,c)) > -EPS;
}

bool onsegment(segment s, point p){
    return colliner(s.first,s.second,p) && onRay(s.first,s.second,p) && onRay(s.second,s.first,p);
}

bool intsegment(segment s1, segment s2){
    double x,y;
    line l1 = getLine(s1);
    line l2 = getLine(s2);
    if (!intline(l1,l2,x,y)) return 0;
    return onsegment(s1, point(x,y)) &&  onsegment(s2, point(x,y));
}

inline bool insideRect(ll x, ll y, ll xl, ll yt, ll xr, ll yb){
  return ((x>=xl && x<=xr && y>=yb && y<=yt ));
}

int lx1,lx2,ly2,ly1,x1,yy1,x2,yy2;

int main(){
//    freopen("i.txt","rt",stdin);
    int t;
    cin>>t;
    while(t--){
        cin>>lx1>>ly1>>lx2>>ly2>>x1>>yy1>>x2>>yy2;
        point lp1(lx1,ly1),lp2(lx2,ly2),r1(x1,yy1),r2(x2,yy2),r3(x1,yy2),r4(x2,yy1);
        segment s = {lp1,lp2};
        segment s1 = {r1,r3};
        segment s2 = {r1,r4};
        segment s3 = {r2,r3};
        segment s4 = {r4,r2};
        bool isInside = insideRect(lx1, ly1, x1, yy1, x2, yy2);
        puts((intsegment(s,s1) || intsegment(s,s2) || intsegment(s,s3) || intsegment(s,s4) || isInside)?"T":"F");
    }
}
