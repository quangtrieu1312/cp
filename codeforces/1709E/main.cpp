#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> a, x, y, adj, d, head, pos;
int main()
{
    cin>>n;
    a.resize(n+1);
    x.resize(n-1);
    y.resize(n-1);
    adj.resize(2*(n-1));
    head.resize(n+2,0);
    pos.resize(n+2,0);
    d.resize(n+1,0);

    for (int i=1; i<=n; i++){
        cin>>a[i];
    }

    for (int i=0; i<n-1; i++){
        cin>>x[i]>>y[i];
        d[x[i]]++;
        d[y[i]]++;
    }
    
    for (int i=1; i<=n+1; i++){
        head[i]=head[i-1]+d[i-1];
        pos[i]=head[i];
    }

    for (int i=0; i<n-1; i++){
        adj[pos[x[i]]++]=y[i];
        adj[pos[y[i]]++]=x[i];
    }

    return 0;
}
