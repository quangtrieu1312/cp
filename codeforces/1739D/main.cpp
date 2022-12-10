#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, n, k;
vector<int> p, u, v, head, adj, pos, d, depth;
vector<bool> visited;
ll res;
void dfs(int x, int dep){
    visited[x]=true;
    depth.push_back(dep);
    for (int i=head[x]; i<head[x+1]; i++){
        if (!visited[adj[i]]){
            dfs(adj[i],dep+1);
        }
    }
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>k;
        p.resize(0);
        p.resize(n+1);

        d.resize(0);
        d.resize(n+1,0);
        u.resize(0);
        v.resize(0);
        adj.resize(0);
        adj.resize(n,0);
        pos.resize(0);
        pos.resize(n+2,0);
        head.resize(0);
        head.resize(n+2,0);


        for (int i=2; i<=n; i++){
            cin>>p[i];
            u.push_back(p[i]);
            v.push_back(i);
            d[p[i]]++;
        }

        for (int i=1; i<=n+1; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }

        for (int i=0; i<u.size(); i++){
            adj[pos[u[i]]++]=v[i];
        }

        visited.resize(0);
        visited.resize(n+1,false);
        depth.resize(0);

        dfs(1,0);
        sort(depth.begin(), depth.end(), greater<int>());

        cout<<"DEBUG DEPTH"<<endl;
        for (int i=0; i<depth.size(); i++){
            cout<<depth[i]<<" " ;
        }
        cout<<endl;
        if (k>=depth.size()){
            res=1;
        } else {
            res=max(1,depth[k]);
        }
        cout<<"DEBUG: ";
        cout<<res<<endl;
    }
    return 0;
}
