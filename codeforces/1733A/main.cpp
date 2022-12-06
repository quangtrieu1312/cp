#include <bits/stdc++.h>

using namespace std;
int t, k, n;
vector<int> a;
long long res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>k;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        res=0;
        for (int i=1; i<=k; i++){
            for (int j=1; i+k*j<=n; j++){
                if (a[i]<a[i+k*j]){
                    swap(a[i],a[i+k*j]);
                }
            }
            res+=a[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
