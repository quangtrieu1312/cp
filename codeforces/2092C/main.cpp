#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> a, odd, even;
int n, t;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        ll res=0;
        a.resize(n);
        odd.resize(0);
        even.resize(0);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        for (int i=0; i<n; i++) {
            if (a[i]&1) {
                odd.push_back(a[i]);
            } else {
                even.push_back(a[i]);
            }
        }
        if (odd.size()==0 || even.size()==0) {
            cout<<a[n-1]<<endl;
        } else {
            ll tmp=0;
            for (int i=0; i<even.size(); i++) {
                tmp+=even[i];
            }
            for (int i=0; i<odd.size()-1; i++) {
                tmp+=odd[i]-1;
            }
            tmp+=odd[odd.size()-1];
            res=max(res,tmp);

            cout<<res<<endl;
        }
    }
    return 0;
}
