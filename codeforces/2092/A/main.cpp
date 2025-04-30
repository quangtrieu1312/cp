#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> a;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n);
        int amax=0, amin=INT_MAX;
        for (int i=0; i<n; i++) {
            cin>>a[i];
            amax=max(amax,a[i]);
            amin=min(amin,a[i]);
        }
        cout<<amax-amin<<endl;
    }
    return 0;
}
