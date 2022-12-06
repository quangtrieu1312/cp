#include <bits/stdc++.h>

using namespace std;
int T, N, K;
bool res;
vector<int> S, cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N>>K;
        cnt.resize(0);
        cnt.resize(101,0);
        S.resize(N+1);
        for (int i=1; i<=N; i++){
            cin>>S[i];
            cnt[S[i]]++;
        }

        res=true;
        if (K*2<N){
            res=false;
        }
        for (int i=1; i<=100; i++){
            if (cnt[i]>2){
                res=false;
            }
        }
        cout<<"Case #"<<casenum<<": ";
        if (res){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
