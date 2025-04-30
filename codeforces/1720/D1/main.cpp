#include <bits/stdc++.h>

using namespace std;
int t, n, res;
vector<int> a, dp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        dp.resize(0);
        dp.resize(n,0);
        dp[0]=1;
        for (int i=1; i<n; i++){
            dp[i]=1;
            for (int j=max(0,i-400); j<i; j++){
                if ((a[j]^i)<(a[i]^j)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        res=0;
        for (int i=0; i<n; i++){
            res=max(res,dp[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
