#include <bits/stdc++.h>

using namespace std;
int n;
int t;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        if (n&1) {
            cout<<n<<" ";
            for (int i=1; i<n; i++) {
                cout<<i<<" ";
            }
            cout<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}
