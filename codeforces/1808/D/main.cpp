#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll l, r;

int cntLength(ll x) {
    if (x==0) return 1;
    int ret = 0;
    while (x>0) {
        ret++;
        x/=10;
    }
    return ret;
}

ll solve() {
    if (l<10) {
        return l;
    }
    ll ret = 0;
    ll diff = r - l;
    int diffLen = cntLength(diff);
    int lLen = cntLength(l);
    if (diffLen > lLen) {
        for (int i=0; i<lLen; i++) {
            ret *= 10;
            ret += 9;
        }
        return ret;
    }

    return ret;
}

int main() {
    cin>>t;
    while (t--) {
        cin>>l>>r;
        cout<<solve()<<endl;
    }
    return 0;
}
