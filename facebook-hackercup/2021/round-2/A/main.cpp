#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int T, N, M;
vector<int> S;
vector< vector<int> > P;
ll res=0;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N>>M;
        S.resize(0);
        S.resize(M);
        P.resize(0);
        P.resize(N,vector<int>(M));
        for (int i=0; i<M; i++){
            cin>>S[i];
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                cin>>P[i][j];
            }
        }

        res=0;

        sort(S.begin(),S.end());
        for (int i=0; i<N; i++){
            sort(P[i].begin(),P[i].end());
        }
        vector<bool> usedcur, usednxt;
        vector<int> cur_v, nxt_v, adj;
        cur_v.resize(0);
        cur_v.resize(M,1);
        for (int i=0; i<N; i++){
            usedcur.resize(0);
            usedcur.resize(M,false);
            usednxt.resize(0);
            usednxt.resize(M,false);
            adj.resize(0);
            adj.resize(M,-1);

            nxt_v.resize(0);
            nxt_v.resize(M,1);

            int r1=0, r2=0;
            while (r1<M && r2<M){
                while (r1<M && S[r1]<P[i][r2]) r1++;
                while (r2<M && P[i][r2]<S[r1]) r2++;
                if (r1==M || r2==M){
                    break;
                }
                if (S[r1]==P[i][r2]){
                    nxt_v[r2]=cur_v[r1];
                    adj[r2]=r1;
                    r1++;
                    r2++;
                } else {
                    r1++;
                }
            }
            for (int j=0; j<M; j++){
                if (adj[j]!=-1){
                    usednxt[j]=true;
                    usedcur[adj[j]]=true;
                }
            }

            r1=0;
            r2=0;
            while (r1<M && r2<M){
                while (r1<M && usedcur[r1]) r1++;
                while (r2<M && usednxt[r2]) r2++;
                if (r1==M || r2==M) break;
                nxt_v[r2]=cur_v[r1]-1;
                r1++;
                r2++;
            }
            vector<pii> tmp;
            for (int j=0; j<M; j++){
                tmp.push_back(pii(P[i][j],nxt_v[j]));
            }
            sort(tmp.begin(),tmp.end());
            for (int j=0; j<M; j++){
                nxt_v[j]=tmp[j].second;
            }
            cur_v.swap(nxt_v);
            S.swap(P[i]);
        }
        res=0;
        for (int i=0; i<M; i++){
            if (cur_v[i]<0){
                res=res+(-cur_v[i]);
            }
        }
        cur_v.resize(0);
        cout<<"Case #"<<casenum<<": "<<res<<endl;
    }
    return 0;
}
