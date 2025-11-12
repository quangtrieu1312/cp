#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> a;
bool ans;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n+1);
        for (int i=1; i<=n; i++) {
            cin>>a[i];
        }
        ans=true;
        sort(a.begin(), a.end());
        for (int i=2; i<n; i+=2) {
            if (a[i]!=a[i+1]) {
                ans=false;
            }
        }
        if (ans) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
