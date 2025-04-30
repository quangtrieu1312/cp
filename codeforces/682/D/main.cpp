#include <bits/stdc++.h>
#define MY_PRIME 1000000007
#define NMAX 1003
using namespace std;
typedef long long ll;
bool isDebug = false;
int n, m, k, ans;
string s, t;

int max_dp_t[NMAX][11];
int dp[NMAX][NMAX][11];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
    cin>>s>>t;
    memset(dp,0,sizeof(dp));
    memset(max_dp_t,0,sizeof(max_dp_t));

    for (int j=m-1; j>=0; j--){
        if (s[n-1]==t[j]){
            dp[n-1][j][1]=1;
        }
        if (j!=m-1){
            max_dp_t[j][1]=max(dp[n-1][j][1],max_dp_t[j+1][1]);
        } else {
            max_dp_t[j][1]=dp[n-1][j][1];
        }
    }
    string debugs, debugt;

    for (int i=n-2; i>=0; i--){
        for (int j=m-1; j>=0; j--){
            for (int p=1; p<=k; p++){
                //if (i>n-p-1 || j>m-p) continue;
                cout<<"........ p="<<p<<" ........."<<endl;
                if (s[i]==t[j]){
                    dp[i][j][p]=1+max_dp_t[j+1][p-1];
                    if (j!=m-1 && s[i+1]==t[j+1]){
                        dp[i][j][p]=max(dp[i][j][p],1+dp[i+1][j+1][p]);
                    }
                }
                if (j!=m-1){
                    max_dp_t[j][p]=max(dp[i][j][p],max_dp_t[j+1][p]);
                } else {
                    max_dp_t[j][p]=dp[i][j][p];
                }
                cout<<"(p,i,j)=("<<p<<","<<i<<","<<j<<")"<<endl;
                cout<<s.substr(i)<<endl;
                cout<<t.substr(j)<<endl;
                cout<<"dp["<<i<<"]["<<j<<"]["<<p<<"]="<<dp[i][j][p]<<endl;
                cout<<"max_dp_t["<<j<<"]["<<p<<"]="<<max_dp_t[j][p]<<endl;
                cout<<"_____________"<<endl;
            }
        }
    }
    ans=max_dp_t[0][k];
    cout<<ans<<endl;
    return 0;
}
/*
3 2 2
abc
ab
----
2




9 12 4
bbaaababb
abbbabbaaaba
------------
7


*/
