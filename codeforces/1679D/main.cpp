#include <bits/stdc++.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define oo LLONG_MAX

using namespace std;

typedef long long int ll;

int n, m, res;
ll k;
vector<int> a, u, v, adj, head, cur, d, color;
vector<ll> dp;

void markColor(int x) {
    for (int i=head[x]; i<head[x+1]; i++) {
        if (color[adj[i]]==WHITE) {
            color[adj[i]]=GRAY;
            markColor(adj[i]);
            dp[x]=max(dp[x], dp[adj[i]]==oo?oo:dp[adj[i]]+1);
        } else if (color[adj[i]]==GRAY) {
            dp[x]=oo;
        } else {
            dp[x]=max(dp[x], dp[adj[i]]==oo?oo:dp[adj[i]]+1);
        }
    }
    color[x]=BLACK;
}

bool solve(ll x) {
    for (int i=1; i<=n; i++) {
        if (a[i]>x) {
            color[i]=BLACK;
            dp[i]=0;
        } else {
            color[i]=WHITE;
            dp[i]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (color[i]==WHITE) {
            color[i]=GRAY;
            markColor(i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (dp[i]>=k) {
            return true;
        }
    }
    return false;
}

void binarySearch(int l, int r) {
    if (l>r) return;
    ll mid;
    while (l<=r) {
        mid=(l+r)/2;
        if (solve(mid)) {
            res=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
}

int main() {
    cin>>n>>m>>k;
    a.resize(n+1);
    u.resize(m);
    v.resize(m);
    adj.resize(m);
    head.resize(n+2,0);
    cur.resize(n+2,0);
    d.resize(n+2,0);
    dp.resize(n+1);
    color.resize(n+1);

    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }

    for (int i=0; i<m; i++) {
        cin>>u[i]>>v[i];
        d[u[i]]++;
    }

    for (int i=1; i<=n+1; i++) {
        head[i]=head[i-1]+d[i-1];
        cur[i]=head[i];
    }

    for (int i=0; i<m; i++) {
        adj[cur[u[i]]++]=v[i];
    }

    res=-1;
    binarySearch(1, 1000000000);
    cout<<res<<endl;

    return 0;
}
