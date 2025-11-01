#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll a, b, c;
bool res;

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b>>c;
        res=false;
        ll diff=b-a;
        a+=diff;
        c-=diff;
        if (c==a) {
            res=true;
        } else if (c>a && (c-a)%3==0) {
            res=true;
        }
        if (res) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
