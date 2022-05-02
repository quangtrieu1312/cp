#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;
vector<int> a;

int main()
{
    cin >> t;
    bool res;
    while (t--){
        cin>>n;
        a.resize(0);
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        if (n<=2){
            cout << "YES\n";
            continue;
        }

        res = true;
        for (int i=2; i<n ; i++){
            if (a[i-2]>=a[i-1] && a[i-1]>=a[i] && a[i-2]>a[i]) {
                res = false;
            }
        }

        if (res){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
