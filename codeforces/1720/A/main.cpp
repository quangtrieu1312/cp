#include <bits/stdc++.h>

using namespace std;
int t;
long long a, b , c, d, res;
long long gcd(long long x, long long y){
    if (x==0 || y==0){
        return max(x,y);
    }
    if (x>y){
        swap(x,y);
    }
    return gcd(x,y%x);
}
int main()
{
    cin>>t;
    while (t--){
        cin>>a>>b>>c>>d;
        res=0;
        long long x=gcd(a,b);
        long long y=gcd(c,d);
        a/=x;
        b/=x;
        c/=y;
        d/=y;
        // a/b c/d
        // a/b a/d
        // a/b c/b
        // a/b a/b
        if (a*d==c*b){
            res=0;
        } else if (gcd(a*d,c*b)==min(a*d,c*b) || a*d==0 || c*b==0){
            res=1;
        } else {
            res=2;
        }
        cout<<res<<endl;
    }
    return 0;
}
