#include <bits/stdc++.h>

using namespace std;
int t, n, res, ind;
vector<int> a, dp[2];
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        dp[0].resize(n);
        dp[1].resize(n);
        res=0;
        ind=-1;
        // dp[0][i] = obmit i-th ele, dp[1][i] = take i-th ele
        dp[0][0] = 0;
        dp[1][0] = 1;

        for (int i=1; i<n; i++){
            dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
            while (ind+1<i && a[ind+1]+1<a[i]) {
                res=max(res, dp[1][ind+1]);
                ind++;
            }
            dp[1][i]=res+1;
        }
        res=max(dp[0][n-1], dp[1][n-1]);
        cout<<res<<endl;
    }
    return 0;
}
