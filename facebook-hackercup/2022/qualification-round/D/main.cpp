#include <bits/stdc++.h>
#define oo 1000000009
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int T, N, M, Q, X, Y;
vector<int> head, pos, u, v, d, adj;
vector<ll> F, C;
map<pii, ll> edge;
ll getEdgeWeight(int x, int y){
    if (x==y){
        return oo;
    }
    if (x>y){
        swap(x,y);
    }
    if (edge.find(pii(x,y))==edge.end()){
        return 0;
    }
    return edge[pii(x,y)];
}
void putEdgeWeight(int x, int y, int w){
    if (x==y){
        return;
    }
    if (x>y){
        swap(x,y);
    }
    edge[pii(x,y)]=w;
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=1; casenum<=T; casenum++){
        cin>>N>>M>>Q;
        head.resize(0);
        adj.resize(0);
        pos.resize(0);
        u.resize(M);
        v.resize(M);
        d.resize(0);
        C.resize(M);

        head.resize(N+2,0);
        pos.resize(N+2,0);
        d.resize(N+1,0);
        adj.resize(2*M);
        F.resize(Q);
        edge.clear();
        for (int i=0; i<M; i++){
            cin>>u[i]>>v[i]>>C[i];
            d[u[i]]++;
            d[v[i]]++;
            putEdgeWeight(u[i],v[i],C[i]);
        }

        for (int i=1; i<=N+1; i++){
            head[i]=head[i-1]+d[i-1];
            pos[i]=head[i];
        }

        for (int i=0; i<M; i++){
            adj[pos[u[i]]++]=v[i];
            adj[pos[v[i]]++]=u[i];
        }

        for (int i=0; i<Q; i++){
            cin>>X>>Y;
            F[i]=getEdgeWeight(X,Y);
            for (int j=head[X]; j<head[X+1]; j++){
                F[i]+=min(getEdgeWeight(X,adj[j]),getEdgeWeight(adj[j],Y));
            }
        }

        cout<<"Case #"<<casenum<<": ";
        for (int i=0; i<Q; i++){
            cout<<F[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
