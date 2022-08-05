#include <bits/stdc++.h>
#define modulo 1000000007
using namespace std;
typedef long long ll;
int T, N;
string W;
vector<ll> dp, cnt_v, cnt_tail_f_v;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=0; casenum<T; casenum++){
        cin>>N;
        cin>>W;
        cnt_v.resize(0);
        cnt_tail_f_v.resize(0);
        int cnt=1, cnt_tail_f=(W[0]=='F');
        char c=(W[0]=='F')?'.':W[0];
        for (int i=1; i<N; i++){
            if (c=='.'){
                if (W[i]!='F'){
                    c=W[i];
                    cnt_tail_f=0;
                } else {
                    cnt_tail_f++;
                }
                cnt++;
            } else {
                if (W[i]!='F' && W[i]!=c){
                    cnt_v.push_back(cnt);
                    cnt_tail_f_v.push_back(cnt_tail_f);
                    c=W[i];
                    cnt=1;
                    cnt_tail_f=0;
                } else if (W[i]!='F') {
                    cnt++;
                    cnt_tail_f=0;
                } else {
                    cnt++;
                    cnt_tail_f++;
                }
            }
        }
        cnt_v.push_back(cnt);
        cnt_tail_f_v.push_back(cnt_tail_f);
        N=cnt_v.size();
        dp.resize(0);
        dp.resize(N,0);
        ll cur_sum_cnt=cnt_v[0], dd=0, debugres, cur_sum_tail_f=cnt_tail_f_v[0];
        for (int i=1; i<N; i++){
            dd=(dd+cur_sum_cnt)%modulo;
            dp[i]=(dp[i-1]+(dd-cur_sum_tail_f)*cnt_v[i])%modulo;
            cur_sum_cnt=cur_sum_cnt+cnt_v[i];
            cur_sum_tail_f=cur_sum_tail_f+cnt_tail_f_v[i];
            debugres=dp[i];
        }
        cout<<"Case #"<<casenum+1<<": "<<dp[N-1]<<endl;
    }
    return 0;
}
