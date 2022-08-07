#include <bits/stdc++.h>

using namespace std;
int T, N, res;
vector<int> A, B, F, adj, head, pos, d;
vector<bool> visited;
int dfs(int start){
   visited[start]=true;
   int ans=0;
   for (int i=head[start]; i<head[start+1]; i++){
        if (!visited[adj[i]]){
            if (F[start]!=F[adj[i]]) ans++;
            ans += dfs(adj[i]);
        }
   }
   return ans;
}
int main()
{
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        res=0;
        cin>>N;
        A.resize(N-1);
        B.resize(N-1);
        F.resize(N+1);
        d.resize(0);
        head.resize(0);
        pos.resize(0);
        adj.resize(0);
        visited.resize(0);
        d.resize(N+1,0);
        head.resize(N+2,0);
        pos.resize(N+2,0);
        adj.resize(2*(N-1));
        visited.resize(N+1,false);
        for (int i=0; i<N-1; i++){
            cin>>A[i]>>B[i];
            d[A[i]]++;
            d[B[i]]++;
        }
        for (int i=1; i<=N; i++){
            cin>>F[i];
        }
        for (int i=1; i<=N+1; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }
        for (int i=0; i<N-1; i++){
            adj[pos[A[i]]++]=B[i];
            adj[pos[B[i]]++]=A[i];
        }
        res=dfs(1);
        cout << "Case #" << casenum << ": "<<res<<endl;
    }
    return 0;
}
