#include <bits/stdc++.h>

using namespace std;
string s;
bool hasRes;
int a, b, t;
int castToInt(string x) {
    int res=0;
    for (int i=0; i<x.length(); i++) {
        res=res*10 + (x[i]-'0');
    }
    return res;
}
bool isSquare(int x) {
    int tmp=floor(sqrt(x));
    return tmp*tmp == x;
}
int main() {
    cin>>t;
    while (t--) {
        cin>>s;
        hasRes=isSquare(castToInt(s));
        if (hasRes) {
            cout<<0<<" "<<floor(sqrt(castToInt(s)))<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}
