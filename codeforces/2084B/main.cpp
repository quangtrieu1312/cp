#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef long long ll;

int t, n, cntmin;
vector<ll> a, b;

ll gcd(ll x, ll y) {
    if (x==0) {
        return y;
    }
    if (y==0) {
        return x;
    }
    if (x>y) {
        swap(x,y);
    }
    return gcd(x,y%x);
}
int main() {
    cin>>t;
    string res;
    while (t--) {
        cin>>n;
        res="no";
        a.resize(n, 0);
        b.resize(0);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        for (int i=1; i<n; i++) {
            if (a[i]%a[0]==0) {
                b.push_back(a[i]/a[0]);
            }
        }
        if (b.size()>0) {
            ll mygcd=b[0];
            for (int i=1; i<b.size(); i++) {
                mygcd=gcd(mygcd,b[i]);
            }
            if (mygcd==1) {
                res="yes";
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
