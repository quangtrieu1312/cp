#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> u, v, adj, head, cnt, cur, dist;
vector<bool> visited;

pii bfs(int x) {
    visited.resize(0);
    visited.resize(n+1, false);
    dist.resize(0);
    dist.resize(n+1,0);
    int res=x;
    queue<pii> q;
    q.push(pii(x,0));
    visited[x]=true;
    while (!q.empty()) {
        pii top=q.front();
        q.pop();
        int node=top.first;
        int d=top.second;
        dist[node]=d;
        if (dist[res]<dist[node]) {
            res=node;
        }
        for (int i=head[node]; i<head[node+1]; i++) {
            if (!visited[adj[i]]) {
                q.push(pii(adj[i],d+1));
                visited[adj[i]]=true;
            }
        }
    }
    return pii(res, dist[res]);
}

int main() {
    cin >> n;
    if (n==1) {
        cout<<1<<endl;
        return 0;
    }
    u.resize(n-1);
    v.resize(n-1);
    adj.resize(2*(n-1));
    head.resize(n+2,0);
    cur.resize(n+2, 0);
    cnt.resize(n+2,0);
    for (int i = 0; i < n-1; i++) {
        cin>>u[i]>>v[i];
        cnt[u[i]]++;
        cnt[v[i]]++;
    }
    for (int i = 1; i <= n+1; i++) {
        head[i]=head[i-1]+cnt[i-1];
        cur[i]=head[i];
    }
    for (int i=0; i<n-1; i++) {
        adj[cur[u[i]]++]=v[i];
        adj[cur[v[i]]++]=u[i];
    }
    int firstEnd = bfs(1).first;
    vector<bool> diameterEnds;
    diameterEnds.resize(n+1, false);
    for (int i=1; i<=n; i++) {
        if (dist[i]==dist[firstEnd]) {
            diameterEnds[i]=true;
        }
    }
    int secondEnd = bfs(firstEnd).first;
    for (int i=1; i<=n; i++) {
        if (dist[i]==dist[secondEnd]) {
            diameterEnds[i]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!diameterEnds[i]) {
            cout<<dist[secondEnd]<<endl;
        } else {
            cout<<dist[secondEnd]+1<<endl;
        }
    }
    return 0;
}
