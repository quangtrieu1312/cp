#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int c, n, q, a, b, x, tmp;
vector<ll> tree, lazy;
vector<int> u, v, adj, cur, head, d, in, out;
vector<bool> visited;

void dfs(int node) {
    in[node]=tmp++;
    for (int i=head[node]; i<head[node+1]; i++) {
        if (!visited[adj[i]]) {
            visited[adj[i]]=true;
            dfs(adj[i]);
        }
    }
    out[node]=tmp++;
}

bool isAncestor(int nodeA, int nodeB) {
    return nodeA!=nodeB && (in[nodeA]<=in[nodeB] && out[nodeB]<=out[nodeA]);
}

void updateTree(int node, int left, int right, int lquery, int  rquery, int delta) {
    if (left>right || right<lquery || rquery<left || lquery>rquery) {
        return;
    }
    if (lazy[node]) {
        tree[node]+=lazy[node];
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if (lquery<=left && right<=rquery) {
        tree[node]+=delta;
        lazy[node*2]+=delta;
        lazy[node*2+1]+=delta;
        return;
    }
    updateTree(node*2,left,(left+right)/2,lquery,rquery,delta);
    updateTree(node*2+1,(left+right)/2+1,right,lquery,rquery,delta);
    tree[node]=tree[node*2]+tree[node*2+1];
    return;
}

ll queryTree(int node, int left, int right, int lquery, int rquery) {
    if (left>right || right<lquery || rquery<left || lquery>rquery) {
        return 0L;
    }
    if (lazy[node]) {
        tree[node]+=lazy[node];
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if (lquery<=left && right<=rquery) {
        return tree[node];
    }
    ll leftQuery=queryTree(node*2,left,(left+right)/2,lquery,rquery);
    ll rightQuery=queryTree(node*2+1,(left+right)/2+1,right,lquery,rquery);
    return leftQuery+rightQuery;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt","r",stdin);
    //freopen("outp.txt","w",stdout);
    cin>>c;
    while (c--) {
        cin>>n>>q;
        u.resize(n-1);
        v.resize(n-1);
        adj.resize(2*(n-1));
        cur.resize(0);
        cur.resize(n+2);
        head.resize(0);
        head.resize(n+2);
        d.resize(0);
        d.resize(n+1);
        in.resize(n+1);
        out.resize(n+1);
        visited.resize(0);
        visited.resize(n+1, false);
        tree.resize(0);
        tree.resize(16*(n+1), 0);
        lazy.resize(0);
        lazy.resize(16*(n+1), 0);
        for (int i=0; i<n-1; i++) {
            cin>>u[i]>>v[i];
            d[u[i]]++;
            d[v[i]]++;
        }
        for (int i=1; i<=n+1; i++) {
            head[i]=head[i-1]+d[i-1];
            cur[i]=head[i];
        }
        for (int i=0; i<n-1; i++) {
            adj[cur[u[i]]++]=v[i];
            adj[cur[v[i]]++]=u[i];
        }
        visited[1]=true;
        tmp=0;
        dfs(1);
        for (int i=0; i<q; i++) {
            cin>>a>>b>>x;
            if (x==0) {
                if (isAncestor(a,b)) {
                    cout<<abs(queryTree(1,0,2*n-1,in[b],out[b]))<<endl;
                } else {
                    cout<<abs(queryTree(1,0,2*n-1,in[a],out[a]))<<endl;
                }
            } else {
                updateTree(1,0,2*n-1,in[a],in[a],x);
                updateTree(1,0,2*n-1,in[b],in[b],-x);
            }
        }
    }
    return 0;
}
