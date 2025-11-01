
#include <bits/stdc++.h>

using namespace std;

int T, N, m, cnt;
vector<int> A, u, v, w, d, head, h, adj, adjw;
vector<bool> visited;

void dfs(int x, int maxWeight) {
    visited[x]=true;
    cnt++;
    for (int i=head[x]; i<head[x+1]; i++) {
        if (!visited[adj[i]] && adjw[i]<=maxWeight) {
            dfs(adj[i], maxWeight);
        }
    }
}

int solve() {
    m=2*N-1;
    cnt=0;
    A[0]=0;
    u.resize(0);
    v.resize(0);
    w.resize(0);
    d.resize(0);
    h.resize(0);
    head.resize(0);
    adj.resize(0);
    adjw.resize(0);
    for (int i=1; i<=N; i++) {
        u.push_back(0);
        v.push_back(i);
        w.push_back(A[i]);
        if (i>1) {
            u.push_back(i);
            v.push_back(i-1);
            w.push_back(abs(A[i]-A[i-1]));
        }
    }
    d.resize(N+1,0);
    head.resize(N+2,0);
    h.resize(N+2,0);
    adj.resize(4*N);
    adjw.resize(4*N);
    for (int i=0; i<m; i++) {
        d[u[i]]++;
        d[v[i]]++;
    }
    for (int i=1; i<=N+1; i++) {
        head[i]=head[i-1]+d[i-1];
        h[i]=head[i];
    }
    for (int i=0; i<m; i++) {
        adj[h[u[i]]]=v[i];
        adjw[h[u[i]]]=w[i];
        h[u[i]]++;
        adj[h[v[i]]]=u[i];
        adjw[h[v[i]]]=w[i];
        h[v[i]]++;
    }
    long long int left=0, right=1000000000;
    int ans=right+1;
    while (left<=right) {
        visited.resize(0);
        visited.resize(N+1,false);
        cnt=0;
        long long int mid=(left+right)/2;
        dfs(0,mid);
        if (cnt==N+1) {
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    return ans;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    cin>>T;
    for (int testCase=1; testCase<=T; testCase++) {
        cin>>N;
        A.resize(N+1);
        for (int i=1; i<=N; i++) {
            cin>>A[i];
        }
        cout<<"Case #"<<testCase<<": "<<solve()<<endl;
    }
    return 0;
}
