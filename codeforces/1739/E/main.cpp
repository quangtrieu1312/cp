#include <bits/stdc++.h>
#define oo 300000
using namespace std;
int n;
vector<string> hallway;
vector< vector< vector<int> > >dp;
int res;
int main()
{
    cin>>n;
    hallway.resize(2);
    cin>>hallway[0];
    cin>>hallway[1];

    dp.resize(2,vector< vector<int> >(2,vector<int>(n,0)));
    //remove or not, row, col
    dp[0][0][0]=0;
    if (hallway[1][0]=='1'){
        dp[0][1][0]=1;
    } else {
        dp[1][1][0]=-oo;
    }
    for (int i=1; i<n; i++){
        if (hallway[0][i]=='1'){
            dp[0][0][i]=max(dp[1][1][i-1]+1,hallway[1][i-1]=='1'?dp[0][1][i-1]:dp[0][1][i-1]+1);
            dp[1][0][i]=max(dp[0][1][i-1],dp[1][1][i-1]);
        } else {
            dp[0][0][i]=max(dp[0][1][i-1],dp[1][1][i-1]);
            dp[1][0][i]=-oo;
        }
        if (hallway[1][i]=='1'){
            dp[0][1][i]=max(dp[1][0][i-1]+1,hallway[0][i-1]=='1'?dp[0][0][i-1]:dp[0][0][i-1]+1);
            dp[1][1][i]=max(dp[0][0][i],dp[1][0][i])+1;
        } else {
            dp[0][1][i]=max(dp[0][0][i],dp[1][0][i]);
            dp[1][1][i]=-oo;
        }
    }
    res=max(dp[0][1][n-1],dp[1][1][n-1]);
    cout<<res<<endl;
    return 0;
}
