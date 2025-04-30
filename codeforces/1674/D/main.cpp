#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;
vector<int> a, c;

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
        int start_ind=n&1;
        for (int i=start_ind; i<n; i+=2){
            if (a[i]>a[i+1]){
                int tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
            }
        }
        for (int i=1; i<n; i++){
            if (a[i]<a[i-1]){
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
