#include <bits/stdc++.h>
#define modulo 1000000007
using namespace std;
int T, N;
string W;
vector<long long> dp;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=0; casenum<T; casenum++){
        dp.resize(0);
        cin>>N;
        cin>>W;
        string tmp="";
        for (int i=0; i<N; i++){
            if (W[i]!='F'){
                tmp+=W[i];
            }
        }
        W=tmp;
        N=W.length();
        dp.resize(N,0);
        char c=W[0];
        int cnt=1, dd;
        for (int i=1; i<N; i++){
            dd=0;
            if (W[i]!=c){
                dp[i]=(dp[i-1]+cnt)%modulo;
                c=W[i];
                cnt=1;
            } else {
                cnt++;
                dp[i]=(dp[i-1]+dp[i-cnt+1])%modulo;
            }
            dd=dp[i];
        }
        cout<<"Case #"<<casenum+1<<": "<<dp[N-1]<<endl;
    }
    return 0;
}
