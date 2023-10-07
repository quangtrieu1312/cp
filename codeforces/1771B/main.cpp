#include <bits/stdc++.h>

using namespace std;
int t;
int n, m;
vector<int> u, v, adj, head, d, pos;
vector<bool> visited;
int main()
{
    cin>>t;
    while (t--){
        u.resize(0);
        v.resize(0);
        d.resize(0);
        adj.resize(0);
        head.resize(0);
        pos.resize(0);
        visited.resize(0);

        cin>>n>>m;
        u.resize(m);
        v.resize(m);
        d.resize(n+1,0);
        adj.resize(2*m);
        head.resize(n+2);
        pos.resize(n+2);
        visited.resize(n+1,false);

        head[0]=0;
        pos[0]=0;
        for (int i=0; i<m; i++){
            // u <-> v = don't know each other
            cin>>u[i]>>v[i];
            d[u[i]]++;
            d[v[i]]++;
        }

        for (int i=1; i<=n+1; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }

        for (int i=0; i<m; i++){
            adj[pos[u[i]]++]=v[i];
            adj[pos[v[i]]++]=u[i];
        }


    }
    return 0;
}
