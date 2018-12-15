#include<iostream>
#include<map>
#include <string>
#include <math.h>

using namespace std;

int main(){
//    map<char,int> city;
//    city['R']=0;
//    char a;
//    cin>>a;
//    city[a] = 1;
//    cout<<city['R']<<endl;
//    cout<<a<<" "<<city[a];
//    char b;
//    cin>>b;
//    cout<<city[b];
//    string a,b;
//    cin>>a>>b;
//    cout<<a[0]<<" "<<b[1];
//    cin>>a;
//    cout<<a[3]<<" "<<b[1];
    /*
    Map iterator to print key value pair
    map<char,int>::iterator pos;
    for (pos = city.begin(); pos != city.end(); ++pos) {
        cout << "key: \"" << pos->first << "\" "<< "value: " << pos->second << endl;
    }
    */
//        int a = 9;
//
//    char b = char(a) +'0';
//
//    char c = (char)a +'0';
//
//    int d = (int)b;
//
//    int e = a & 0xff;
//
//    cout << a <<endl<< b <<endl<< c << endl << d << endl<< e << endl;
//    string a = "abc";
//    cout<<(int) a[1]-'a';
//    float m = 4.7;
//    float mm = m*1000000;
//    int mf = mm;
    int x = 5;
    for (int i=7;i>=0;i--)
        cout<<((x>>i)&1);
}
