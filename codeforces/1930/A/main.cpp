#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;
vector<int> a;
ll sum;

int main() {
    cin>>t;
    while (t--) {
        sum=0;
        cin>>n;
        a.resize(2*n+1);
        for (int i=1; i<=2*n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        for (int i=1; i<=2*n; i+=2) {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
