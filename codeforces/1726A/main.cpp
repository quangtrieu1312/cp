#include <bits/stdc++.h>

using namespace std;
int t, n, res;
vector<int> a;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n+1);
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        int nxt;
        res=0;
        for (int i=1; i<=n; i++){
            nxt=i+1;
            if (nxt>n){
                nxt=1;
            }
            res=max(res,a[i]-a[nxt]);
        }
        for (int i=1; i<=n; i++){
            if (i!=1){
                res=max(res,a[i]-a[1]);
            }
            if (i!=n){
                res=max(res,a[n]-a[i]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
