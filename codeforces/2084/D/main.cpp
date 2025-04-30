#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>m>>k;
        int tmp=n/(m+1);
        if (n<(m+1)*k) {
            for (int i=0; i<n; i++) {
                cout<<i%k<<" ";
            }
        } else {
            for (int i=0; i<n; i++) {
                cout<<i%tmp<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
