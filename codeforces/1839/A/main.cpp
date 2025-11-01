#include <bits/stdc++.h>

using namespace std;

int t, n , k, ans;
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        ans = ceil(1.0*n/k);
        if (n%k != 1 && k!=1) {
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
