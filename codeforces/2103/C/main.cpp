#include <bits/stdc++.h>
#include <ratio>

using namespace std;

int t, n, k;
vector<int> a;
bool res;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        a.resize(n+1);
        for (int i=1; i<=n; i++) {
            cin>>a[i];
        }
        res=false;

        if (res) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
