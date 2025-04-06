#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, q, a, b, c, tmp;
vector<int> u, v, adj, head, cnt, cur, dist, entrance, departure;
vector< vector<int> > lift;
vector<bool> visited;

void dfs(int x) {
    entrance[x]=tmp;
    for (int i=head[x]; i<head[x+1]; i++) {
        if (!visited[adj[i]]) {
            tmp++;
            visited[adj[i]]=true;
            dist[adj[i]]=dist[x]+1;
            lift[adj[i]][0]=x;
            dfs(adj[i]);
        }
    }
    departure[x]=tmp;
}
bool isAncestor(int x, int y) {
    return (entrance[x] <= entrance[y] && departure[y] <= departure[x]);
}

int highestNonAncestor(int x, int y) {
    for (int i=__lg(dist[x]); i>=0;) {
        if (!isAncestor(lift[x][i],y)) {
            x=lift[x][i];
            i=__lg(dist[x]);
        } else {
            i--;
        }
    }
    return x;
}

int lca(int x, int y) {
    if (isAncestor(x,y)) {
        return x;
    } else if (isAncestor(y,x)) {
        return y;
    } else {
        return lift[highestNonAncestor(x,y)][0];
    }
}

int doLifting(int x, int step) {
    if (step==0) return x;
    if (step>=dist[x]) return 1;
    for (int i=__lg(step); i>=0; i--) {
        if ((step>>i)&1) x=lift[x][i];
    }
    return x;
}
int main() {
    iostream::sync_with_stdio(false);
    cin >> n;
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
    visited.resize(0);
    visited.resize(n+1, false);
    dist.resize(0);
    dist.resize(n+1, 0);
    entrance.resize(0);
    entrance.resize(n+1, 0);
    departure.resize(0);
    departure.resize(n+1, 0);
    lift.resize(0);
    lift.resize(n+1,vector<int>(__lg(n)+1));
    visited[1]=true;
    tmp=0;
    dfs(1);
    for (int j=1; (1<<j)<=n; j++) {
        for (int i=2; i<=n; i++) {
            if ((1<<j)<=dist[i]){
                lift[i][j]=lift[lift[i][j-1]][j-1];
            }
        }
    }
    cin>>q;
    for (int i=0; i<q; i++) {
        cin>>a>>b>>c;
        int midway=lca(a,b);
        if (midway==a) {
            cout<<doLifting(b, dist[b]-dist[a]-min(c,dist[b]-dist[a]))<<endl;
        } else if (midway==b) {
            cout<<doLifting(a,min(c,dist[a]-dist[b]))<<endl;
        } else {
            int d1=dist[a]-dist[midway];
            int d2=dist[b]-dist[midway];
            if (c>=d1+d2) {
                cout<<b<<endl;
                continue;
            }
            if (c<d1) {
                cout<<doLifting(a, c)<<endl;
            } else {
                c=c-d1;
                cout<<doLifting(b,d2-c)<<endl;
            }
        }
    }
    return 0;
}
