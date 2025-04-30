#include <bits/stdc++.h>

using namespace std;

int n, q, t, x, y, tmp=0;
vector<int> adj, head, cur, d, u, v, in, out;
vector<long double> tree, lazy;
vector<bool> visited;

void dfs(int node) {
    stack<int> st;
    st.push(node);
    in[node]=tmp++;
    while (!st.empty()) {
        node=st.top();
        while (cur[node]<head[node+1] && visited[adj[cur[node]]]) {
            cur[node]++;
        }
        if (cur[node]<head[node+1]) {
            visited[adj[cur[node]]]=true;
            in[adj[cur[node]]]=tmp++;
            st.push(adj[cur[node]++]);
        } else {
            out[node]=tmp++;
            st.pop();
        }
    }
}

void buildTree(int node, int left, int right) {
    if (left>right) {
        return;
    }
    if (left==right) {
        tree[node]=0.0;
        lazy[node]=0.0;
        return;
    }
    buildTree(2*node, left, (left+right)/2);
    buildTree(2*node+1, (left+right)/2+1, right);
    long double leftNode=tree[2*node];
    long double rightNode=tree[2*node+1];
    tree[node]=leftNode+rightNode;
    lazy[node]=0.0;
}

long double queryTree(int node, int left, int right, int lquery, int rquery) {
    if (left>right || lquery>rquery || right<lquery || rquery<left) {
        return 0.0;
    }
    if (lazy[node]) {
        tree[node]+=lazy[node];
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        lazy[node]=0.0;
    }
    if (lquery<=left && right<=rquery) {
        return tree[node];
    }
    long double leftQuery=queryTree(2*node, left, (left+right)/2, lquery, rquery);
    long double rightQuery=queryTree(2*node+1,(left+right)/2+1,right,lquery,rquery);
    return leftQuery+rightQuery;
}

void updateTree(int node, int left, int right, int lquery, int rquery, long double val) {
    if (left>right || lquery>rquery || right<lquery || rquery<left) {
        return;
    }
    if (lazy[node]) {
        tree[node]+=lazy[node];
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        lazy[node]=0.0;
    }
    if (lquery<=left && right<=rquery) {
        long double delta=val-tree[node];
        tree[node]+=delta;
        lazy[2*node]+=delta;
        lazy[2*node+1]+=delta;
        return;
    }
    updateTree(2*node,left,(left+right)/2,lquery,rquery,val);
    updateTree(2*node+1,(left+right)/2+1,right,lquery,rquery,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

long double solve(int a, int b) {
    long double subTreeA=queryTree(1, 0, tmp-1, in[a], out[a]);
    long double subTreeB=queryTree(1, 0, tmp-1, in[b], out[b]);
    if (subTreeA-subTreeB >= 21) {
        return 1000000000.0;
    }
    long double ans=exp(subTreeA-subTreeB);
    if (ans>=1000000000.0) {
        return 1000000000.0;
    } else {
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    //freopen("outp.txt", "w", stdout);
    cin>>n;
    u.resize(n-1);
    v.resize(n-1);
    adj.resize(2*(n-1));
    head.resize(n+2,0);
    cur.resize(n+2,0);
    d.resize(n+2,0);
    visited.resize(n+1, false);
    in.resize(n+1);
    out.resize(n+1);
    tree.resize(16*(n+1));
    lazy.resize(16*(n+1));
    for (int i=0; i<n-1; i++) {
        cin>>u[i]>>v[i];
        d[u[i]]++;
        d[v[i]]++;
    }
    d[0]=0;
    head[0]=0;
    for (int i=1; i<=n+1; i++) {
        head[i]=head[i-1]+d[i-1];
        cur[i]=head[i];
    }
    for (int i=0; i<n-1; i++) {
        adj[cur[u[i]]++]=v[i];
        adj[cur[v[i]]++]=u[i];
    }
    for (int i=1; i<=n+1; i++) {
        cur[i]=head[i];
    }
    visited[1]=true;
    tmp=0;
    dfs(1);
    buildTree(1,0,tmp-1);
    cin>>q;
    while (q--) {
        cin>>t>>x>>y;
        if (t==1) {
            updateTree(1,0,tmp-1,in[x], in[x], log(y));
        } else {
            cout<<fixed<<showpoint<<setprecision(7)<<solve(x, y)<<endl;
        }
    }
    return 0;
}
