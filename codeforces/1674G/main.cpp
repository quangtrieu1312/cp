#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> u, v, d, dd, adj, head, it, dep;

int dfs(int src){
    //dep[i] = max reversed-depth of node i
    //meaning it takes dep[i] steps to traverse from node i to terminal node
    if (dep[src]!=0){
        //already computed
        return dep[src];
    }
    if (d[src]<=1){
        // if have <= 1 outbound edge
        // => we must trim that edge
        // => is terminal node
        // cout << "Terminal node, dep[" << src << "]=1"<<endl;
        dep[src]=1;
        return dep[src];
    }

    int res=1;
    for (int i=head[src]; i<head[src+1]; i++){
        if (dd[adj[i]]>1){
            // next node must have >1 inbound edge
            // or else next node will be trimmed
            res=max(res,1+dfs(adj[i]));
        }
    }
    dep[src]=res;

    //cout << "dep[" << src << "]=" <<res<<endl;
    return dep[src];
}

int main()
{
    cin>>n>>m;
    u.resize(m);
    v.resize(m);
    d.resize(n+2,0);
    adj.resize(m+2,0);
    it.resize(n+2,0);
    head.resize(n+2,0);
    dd.resize(n+2,0);
    dep.resize(n+2,0);

    for (int i=0; i<m; i++){
        cin>>u[i]>>v[i];
        d[u[i]]++;
        dd[v[i]]++;
    }

    head[0]=0;
    it[0]=0;
    for (int i=1; i<=n+1; i++){
        head[i]=head[i-1]+d[i-1];
        it[i]=head[i];
    }

    for (int i=0; i<m; i++){
        adj[it[u[i]]]=v[i];
        it[u[i]]++;
    }

    int res=0;

    for (int i=1; i<=n; i++){
        res=max(res,dfs(i));
    }

    cout<<res<<endl;
    return 0;
}
