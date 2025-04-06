#include <bits/stdc++.h>

using namespace std;

int t, n;
string a, b;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        cin>>a>>b;
        int a0=0, b0=0;
        for (int i=0; i<n; i++) {
            if (i&1) {
                if (b[i]=='0') {
                    a0++;
                }
                if (a[i]=='0') {
                    b0++;
                }
            } else {
                if (a[i]=='0') {
                    a0++;
                }
                if (b[i]=='0') {
                    b0++;
                }
            }
        }
        if (n&1) {
            if (a0>=(n+1)/2 && b0>=n/2) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else {
            if (a0>=n/2 && b0>=n/2) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
