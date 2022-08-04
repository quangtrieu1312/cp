#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;
ll k;
vector<int> a, u, v, adj, head, pos, d;
int main()
{
    cin>>n>>m>>k;
    a.resize(n+1);
    u.resize(m);
    v.resize(m);
    adj.resize(m);
    d.resize(n+1,0);
    pos.resize(n+2,0);
    head.resize(n+2,0);

    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=0; i<m; i++){
        cin>>u[i]>>v[i];
        d[u[i]]++;
    }
    for (int i=1; i<=n+1; i++){
        head[i]=head[i-1]+d[i-1];
        pos[i]=head[i];
    }
    for (int i=0; i<m; i++){
        adj[pos[u[i]]++]=v[i];
    }
    return 0;
}
