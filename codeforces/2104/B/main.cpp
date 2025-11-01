#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;
vector<int> a, prefmax;
vector<ll> sufsum;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        prefmax.resize(0);
        prefmax.resize(n,0);
        sufsum.resize(0);
        sufsum.resize(n+1,0);
        prefmax[0]=a[0];
        for (int i=1; i<n; i++) {
            prefmax[i]=max(a[i],prefmax[i-1]);
        }
        for (int i=n-1; i>=0; i--) {
            sufsum[i]=sufsum[i+1]+a[i];
        }
        for (int i=n-1; i>0; i--) {
            cout<<max(sufsum[i],sufsum[i+1]+prefmax[i-1])<<" ";
        }
        cout<<sufsum[0]<<endl;
    }
    return 0;
}
