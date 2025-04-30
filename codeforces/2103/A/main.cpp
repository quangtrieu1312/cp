#include <bits/stdc++.h>

using namespace std;

int t, n, res;
vector<int> a;
vector<bool> m;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n+1);
        m.resize(0);
        m.resize(n+1, false);
        res=0;
        for (int i=1; i<=n; i++) {
            cin>>a[i];
            if (!m[a[i]]) {
                m[a[i]]=true;
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
