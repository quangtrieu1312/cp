#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m, q, a, b, tmp=0;
vector<int> u, v, w, adj, weight, head, cur, cnt, inNode, outNode, h;
vector<bool> visited;
vector< vector<pii> > up;

void dfs(int x) {
    visited[x]=true;
    up[x][0]=pii(x,INT_MAX);
    stack<int> st;
    st.push(x);
    inNode[x]=++tmp;
    h[x]=0;
    while (!st.empty()) {
        int node=st.top();
        int nextNode;
        int nextWeight;
        if (cur[node]<head[node+1]) {
            nextNode=adj[cur[node]];
            nextWeight=weight[cur[node]];
        } else {
            outNode[node]=++tmp;
            st.pop();
            continue;
        }
        while (cur[node]<head[node+1]-1 && visited[nextNode]) {
            cur[node]++;
            nextNode=adj[cur[node]];
            nextWeight=weight[cur[node]];
        }
        if (visited[nextNode]) {
            outNode[node]=++tmp;
            st.pop();
            continue;
        } else {
            cur[node]++;
            visited[nextNode]=true;
            up[nextNode][0]=pii(node,nextWeight);
            h[nextNode]=h[node]+1;
            inNode[nextNode]=++tmp;
            st.push(nextNode);
        }
    }
    for (int i=1; i<=__lg(n); i++) {
        for (int j=1; j<=n; j++) {
            int midway=up[j][i-1].first;
            up[j][i]=pii(up[midway][i-1].first,
                           min(up[j][i-1].second,up[midway][i-1].second));
        }
    }
}

void dfs2(int x) {
    inNode[x]=++tmp;
    for (int i=1; i<=__lg(n); i++) {
        int midway=up[x][i-1].first;
        up[x][i]=pii(up[midway][i-1].first,
                    min(up[x][i-1].second,up[midway][i-1].second));
    }
    for (int i=head[x]; i<head[x+1]; i++) {
        if (!visited[adj[i]]) {
            visited[adj[i]]=true;
            h[adj[i]]=h[x]+1;
            up[adj[i]][0]=pii(x,weight[i]);
            dfs2(adj[i]);
        }
    }
    outNode[x]=++tmp;
}
bool isAncestor(int x, int y) {
    return inNode[x]<=inNode[y] && outNode[y]<=outNode[x];
}

int lca(int x, int y) {
    if (isAncestor(x,y)) {
        return x;
    } else if (isAncestor(y,x)) {
        return y;
    } else {
        for (int i=__lg(n); i>=0; i--) {
            if (!isAncestor(up[x][i].first, y)) {
                x=up[x][i].first;
            }
        }
        return up[x][0].first;
    }
}

pii lift(int x, int step) {
    pii res = pii(x,INT_MAX);
    while (step) {
        int power2=__lg(step);
        res.first=up[x][power2].first;
        res.second=min(res.second,up[x][power2].second);
        x=res.first;
        step^=(1<<power2);
    }
    return res;
}

int main() {
    cin>>n>>m;
    u.resize(m);
    v.resize(m);
    w.resize(m);
    adj.resize(0);
    adj.resize(2*m, 0);
    weight.resize(0);
    weight.resize(2*m, 0);
    head.resize(0);
    head.resize(n+2, 0);
    cur.resize(0);
    cur.resize(n+2, 0);
    cnt.resize(0);
    cnt.resize(n+2, 0);
    visited.resize(0);
    visited.resize(n+1, false);
    h.resize(0);
    h.resize(n+1, 0);
    up.resize(0);
    up.resize(n+1, vector<pii>(__lg(n)+1));
    inNode.resize(0);
    inNode.resize(n+1,0);
    outNode.resize(0);
    outNode.resize(n+1,0);
    for (int i=0; i<m; i++) {
        cin>>u[i]>>v[i]>>w[i];
        cnt[u[i]]++;
        cnt[v[i]]++;
    }
    head[0]=0;
    cnt[0]=0;
    for (int i=1; i<=n+1; i++) {
        head[i]=head[i-1]+cnt[i-1];
        cur[i]=head[i];
    }
    for (int i=0; i<m; i++) {
        adj[cur[u[i]]]=v[i];
        adj[cur[v[i]]]=u[i];
        weight[cur[u[i]]++]=w[i];
        weight[cur[v[i]]++]=w[i];
    }
    for (int i=1; i<=n+1; i++) {
        cur[i]=head[i];
    }
    dfs(1);

    //visited[1]=true;
    //up[1][0]=pii(1,INT_MAX);
    //dfs2(1);

    cin>>q;
    for (int i=0; i<q; i++) {
        cin>>a>>b;
        int midway=lca(a,b);
        cout<<min(lift(a,h[a]-h[midway]).second,
                  lift(b,h[b]-h[midway]).second)<<endl;
    }
    return 0;
}
